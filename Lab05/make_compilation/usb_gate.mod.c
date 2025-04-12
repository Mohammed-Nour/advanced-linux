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
	{ 0x122c3a7e, "_printk" },
	{ 0x5b1888e1, "dev_number" },
	{ 0x4bb4bc0f, "stack_class" },
	{ 0x1ec4740d, "device_destroy" },
	{ 0x397ec880, "device_create" },
	{ 0x7f4714a, "usb_deregister" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbc621c09, "usb_register_driver" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x2273f01b, "module_layout" },
};

MODULE_INFO(depends, "int_stack");

MODULE_ALIAS("usb:v046DpC328d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "0F26DA34648F9F1CB5A1EB2");
