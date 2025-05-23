#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x397ec880, "device_create" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x122c3a7e, "_printk" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x7c127ea2, "cdev_del" },
	{ 0x226c7554, "class_destroy" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x37a0cba, "kfree" },
	{ 0x1ec4740d, "device_destroy" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd8287c5f, "cdev_init" },
	{ 0x1289fbda, "cdev_add" },
	{ 0x133353bd, "class_create" },
	{ 0x2273f01b, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "335BFC659C02B45496E4906");
