#include <linux/module.h>
#include <linux/usb.h>
#include <linux/device.h>
#include <linux/cdev.h>

// Imported from int_stack.ko
extern dev_t dev_number;
extern struct class *stack_class;

static struct usb_device_id pen_table[] = {
    { USB_DEVICE(0x046d, 0xc328) },  // keyboard's VID:PID
    {}
};
MODULE_DEVICE_TABLE(usb, pen_table);

static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "USB key (%04X:%04X) inserted\n", id->idVendor, id->idProduct);

    if (stack_class) {
        device_create(stack_class, NULL, dev_number, NULL, "int_stack");
        printk(KERN_INFO "int_stack: device created by USB key\n");
    }

    return 0;
}

static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "USB key removed, removing /dev/int_stack\n");
    device_destroy(stack_class, dev_number);
}

static struct usb_driver pen_driver = {
    .name = "usb_stack_gate",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};

static int __init pen_init(void)
{
    return usb_register(&pen_driver);
}

static void __exit pen_exit(void)
{
    usb_deregister(&pen_driver);
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohamad Nour Shahin");
MODULE_DESCRIPTION("USB Gating Module for int_stack");
