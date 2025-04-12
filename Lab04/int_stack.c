#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/ioctl.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohamad Nour Shahin");
MODULE_DESCRIPTION("Integer Stack Kernel Module");

#define DEVICE_NAME "int_stack"
#define STACK_IOCTL_MAGIC 's'
#define STACK_IOCTL_SET_SIZE _IOW(STACK_IOCTL_MAGIC, 1, int)

static dev_t dev_number;
static struct class *stack_class = NULL;
static struct cdev stack_cdev;

struct int_stack {
    int *data;
    int top;
    int max_size;
    struct mutex lock;
};

static struct int_stack stack;

static int stack_open(struct inode *inode, struct file *file) {
    return 0;
}

static int stack_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t stack_read(struct file *file, char __user *buf, size_t len, loff_t *offset) {
    int value;
    if (len < sizeof(int))
        return -EINVAL;

    if (mutex_lock_interruptible(&stack.lock))
        return -ERESTARTSYS;

    if (stack.top == 0) {
        mutex_unlock(&stack.lock);
        return 0; // NULL equivalent
    }

    value = stack.data[--stack.top];
    mutex_unlock(&stack.lock);

    if (copy_to_user(buf, &value, sizeof(int)))
        return -EFAULT;

    return sizeof(int);
}

static ssize_t stack_write(struct file *file, const char __user *buf, size_t len, loff_t *offset) {
    int value;
    if (len < sizeof(int))
        return -EINVAL;

    if (copy_from_user(&value, buf, sizeof(int)))
        return -EFAULT;

    if (mutex_lock_interruptible(&stack.lock))
        return -ERESTARTSYS;

    if (stack.top >= stack.max_size) {
        mutex_unlock(&stack.lock);
        return -ERANGE;
    }

    stack.data[stack.top++] = value;
    mutex_unlock(&stack.lock);
    return sizeof(int);
}

static long stack_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int new_size;
    int *new_data;

    if (cmd != STACK_IOCTL_SET_SIZE)
        return -EINVAL;

    if (copy_from_user(&new_size, (int __user *)arg, sizeof(int)))
        return -EFAULT;

    if (new_size <= 0)
        return -EINVAL;

    new_data = kmalloc_array(new_size, sizeof(int), GFP_KERNEL);
    if (!new_data)
        return -ENOMEM;

    mutex_lock(&stack.lock);
    kfree(stack.data);
    stack.data = new_data;
    stack.top = 0;
    stack.max_size = new_size;
    mutex_unlock(&stack.lock);

    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = stack_open,
    .release = stack_release,
    .read = stack_read,
    .write = stack_write,
    .unlocked_ioctl = stack_ioctl,
};

static int __init int_stack_init(void) {
    int ret;

    ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
    if (ret < 0)
        return ret;

    cdev_init(&stack_cdev, &fops);
    stack_cdev.owner = THIS_MODULE;

    ret = cdev_add(&stack_cdev, dev_number, 1);
    if (ret < 0) {
        unregister_chrdev_region(dev_number, 1);
        return ret;
    }

    stack_class = class_create("int_stack_class");
    if (IS_ERR(stack_class)) {
        cdev_del(&stack_cdev);
        unregister_chrdev_region(dev_number, 1);
        return PTR_ERR(stack_class);
    }

    if (device_create(stack_class, NULL, dev_number, NULL, DEVICE_NAME) == NULL) {
        class_destroy(stack_class);
        cdev_del(&stack_cdev);
        unregister_chrdev_region(dev_number, 1);
        return -1;
    }

    mutex_init(&stack.lock);
    stack.data = NULL;
    stack.top = 0;
    stack.max_size = 0;

    pr_info("int_stack module loaded. Device: /dev/%s\n", DEVICE_NAME);
    return 0;
}

static void __exit int_stack_exit(void) {
    mutex_destroy(&stack.lock);
    kfree(stack.data);
    device_destroy(stack_class, dev_number);
    class_destroy(stack_class);
    cdev_del(&stack_cdev);
    unregister_chrdev_region(dev_number, 1);
    pr_info("int_stack module unloaded\n");
}

module_init(int_stack_init);
module_exit(int_stack_exit);
