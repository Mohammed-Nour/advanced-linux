#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "stack_ioctl.h"

#define DEVICE_PATH "/dev/int_stack"

void usage() {
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "  kernel_stack set-size <n>\n");
    fprintf(stderr, "  kernel_stack push <n>\n");
    fprintf(stderr, "  kernel_stack pop\n");
    fprintf(stderr, "  kernel_stack unwind\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
        return EXIT_FAILURE;
    }

    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        if (errno == ENOENT) {
            fprintf(stderr, "ERROR: USB key not inserted\n");
            return EXIT_FAILURE;
        }
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    int ret = 0;

    if (strcmp(argv[1], "set-size") == 0) {
        if (argc != 3) {
            usage();
            close(fd);
            return EXIT_FAILURE;
        }

        int size = atoi(argv[2]);
        if (size <= 0) {
            fprintf(stderr, "ERROR: size should be > 0\n");
            close(fd);
            return EXIT_FAILURE;
        }

        ret = ioctl(fd, STACK_IOCTL_SET_SIZE, &size);
        if (ret < 0) {
            perror("ioctl");
            close(fd);
            return errno;
        }

    } else if (strcmp(argv[1], "push") == 0) {
        if (argc != 3) {
            usage();
            close(fd);
            return EXIT_FAILURE;
        }

        int val = atoi(argv[2]);
        ret = write(fd, &val, sizeof(int));
        if (ret < 0) {
            if (errno == ERANGE) {
                fprintf(stderr, "ERROR: stack is full\n");
            } else {
                perror("write");
            }
            close(fd);
            return -ERANGE;  // match kernel module style
        }

    } else if (strcmp(argv[1], "pop") == 0) {
        int val;
        ret = read(fd, &val, sizeof(int));
        if (ret == 0) {
            printf("NULL\n");
        } else if (ret < 0) {
            perror("read");
            close(fd);
            return errno;
        } else {
            printf("%d\n", val);
        }

    } else if (strcmp(argv[1], "unwind") == 0) {
        int val;
        while ((ret = read(fd, &val, sizeof(int))) > 0) {
            printf("%d\n", val);
        }

        if (ret < 0) {
            perror("read");
            close(fd);
            return errno;
        }

    } else {
        usage();
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);
    return 0;
}
