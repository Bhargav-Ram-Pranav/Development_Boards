#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

#include <linux/proc_fs.h>
#include <linux/slab.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<asm/io.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/err.h>
#include <asm/io.h>
#define GPIO_BASE 0x4804C000
unsigned int *gpio;
unsigned int *temp;
unsigned int *out;


static int __init gpio_init(void)
{
	printk("welcome to my driver!...");
	temp=(unsigned int *)ioremap(GPIO_BASE,PAGE_SIZE);
	gpio=(unsigned int *)((char*)temp+0x13C);
	out=(unsigned int *)((char*)temp+0x134);
	*out &= ~(0x1<<17);
	

	*gpio |=(0x1<<17); //direction is set
	return 0;
}
static void  __exit gpio_exit(void)
{
	*gpio &= ~(0x1<<17);
	printk("driver unloaded!...");
	iounmap(temp);

}
module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bare Metal Programming");
MODULE_DESCRIPTION("Test of writing drivers for BBB");

