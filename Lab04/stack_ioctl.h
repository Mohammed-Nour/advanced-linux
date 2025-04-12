#ifndef STACK_IOCTL_H
#define STACK_IOCTL_H

#include <linux/ioctl.h>

#define STACK_IOCTL_MAGIC 's'
#define STACK_IOCTL_SET_SIZE _IOW(STACK_IOCTL_MAGIC, 1, int)

#endif
