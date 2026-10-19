/* hello_module.c -- a minimal Linux loadable kernel module (LKM).
 * Build:   make                  (needs the kernel headers package)
 * Load:    sudo insmod hello_module.ko
 * Check:   lsmod | grep hello    and    sudo dmesg | tail -2
 * Unload:  sudo rmmod hello_module
 * Try this only in a virtual machine you are allowed to break!
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MCMP117");
MODULE_DESCRIPTION("Hello-world kernel module");

static int __init hello_init(void)      /* runs at insmod */
{
    pr_info("hello_module: loaded into the kernel\n");
    return 0;                           /* 0 = success */
}

static void __exit hello_exit(void)     /* runs at rmmod */
{
    pr_info("hello_module: removed from the kernel\n");
}

module_init(hello_init);
module_exit(hello_exit);
