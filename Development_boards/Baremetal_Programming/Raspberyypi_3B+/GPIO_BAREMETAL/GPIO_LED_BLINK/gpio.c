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
#define GPIO_BASE 0xFE200000
unsigned int *gpio;
unsigned int *gpioset;
unsigned int *gpioclr;
unsigned int *temp;


static int __init gpio_init(void)
{
	printk("welcome to my driver!...");
	temp=(unsigned int *)ioremap(GPIO_BASE,PAGE_SIZE);
	gpio=(unsigned int *)((char*)temp+0x00);
	gpioset=(unsigned int *)((char*)temp+0x1C);
	gpioclr=(unsigned int *)((char*)temp+0x28);

	*gpio &=~(0x7<<18);
	*gpio |=(0x1<<18); //direction is set

	*gpioset |= (0x1<<6);


	return 0;
}
static void  __exit gpio_exit(void)
{
	*gpioclr |= (0x1<<6);
	printk("driver unloaded!...");
	iounmap(temp);

}
module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bare Metal Programming");
MODULE_DESCRIPTION("Test of writing drivers for RASPI");
MODULE_VERSION("1.0");

