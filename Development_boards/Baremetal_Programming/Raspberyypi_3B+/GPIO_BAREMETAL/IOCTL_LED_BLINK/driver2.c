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

#define LLL_MAX_USER_SIZE 1024

#define BCM2837_GPIO_ADDRESS 0x3F200000  
#define BCM2711_GPIO_ADDRESS 0xfe200000

static unsigned int *gpio_registers = NULL;
#define PIN_ON _IOW('c','a',int32_t*)

int32_t val =0;



static struct class *ptr;
static	struct device *temp;

static ssize_t myread (struct file *, char __user *, size_t, loff_t *);
static	ssize_t mywrite (struct file *, const char __user *, size_t, loff_t *);
static int myopen(struct inode *, struct file *);
static int myclose(struct inode *, struct file *);
static long myioctl(struct file *file,unsigned int cmd,unsigned long arg) ;
dev_t devno;
struct cdev mycdev;
struct file_operations f_ops =
{
	.open = myopen,
	.release = myclose,
	.unlocked_ioctl = myioctl
	



};

static int myopen(struct inode *inode , struct file *file)
{
	printk(KERN_INFO"device file is opene sucessfully\n");

	try_module_get(THIS_MODULE);


	if(file->f_mode & FMODE_READ)
		printk(KERN_INFO"open for read mode");

	if(file->f_mode & FMODE_WRITE)
		printk(KERN_INFO"open for write mode");

	return 0;
}

static int myclose(struct inode *inode , struct file *file)
{
	
	module_put(THIS_MODULE);
	printk(KERN_INFO"device file is closed\n");
	return 0;
}
static int __init gpio_driver_init(void)
{
	unsigned int pin = 26;
	printk("Welcome to my driver!\n");
	int ret;

	ret = alloc_chrdev_region(&devno, 0,1, "GPIO_RPI");
	if(ret < 0)
	{
		pr_info("failed registration\n");
		return -1;
	}
	else
	{
		pr_info("sucessful registration devno: %d\n",devno);
		
	}

	cdev_init(&mycdev, &f_ops);


	cdev_add(&mycdev, devno, 1);


	/* mapping GPIO physical address to get virtual address */

        pr_info("CREATING DEVICE FILE DYNAMICALLY\n");

       ptr = class_create(THIS_MODULE,"sysmychar1");
       if(ptr ==NULL)
       {
	       pr_info("failed to create class\n");
	       return 1;
       }
       pr_info("ko file object:%p\n",ptr);

       temp = device_create(ptr , NULL ,devno, NULL,"GPIO_DEV");
       if(temp == NULL)
       {
	       pr_info("failed to create file\n");
	       return 1;
       }
       pr_info("device file address:%p\n",temp);
	
	gpio_registers = (int*)ioremap(BCM2837_GPIO_ADDRESS, PAGE_SIZE);
	if (gpio_registers == NULL)
	{
		printk("Failed to map GPIO memory to driver\n");
		return -1;
	}
	unsigned int *fsel_reg = (unsigned int *)((char *)gpio_registers + 0x08);
	unsigned int *gpset_reg = (unsigned int *)((char *)gpio_registers + 0x1C);
	unsigned int *gpclr_reg = (unsigned int *)((char *)gpio_registers + 0x28);

	printk("Successfully mapped in GPIO memory\n");


	
	*fsel_reg &= ~(0x7 << 18);
	*fsel_reg |= (0x1 << 18);
	
	return 0;
}
static long myioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned int *fsel_reg = (unsigned int *)((char *)gpio_registers + 0x08);
	unsigned int *gpset_reg = (unsigned int *)((char *)gpio_registers + 0x1C);
	unsigned int *gpclr_reg = (unsigned int *)((char *)gpio_registers + 0x28);
         switch(cmd) {
                case PIN_ON:
                        if( copy_from_user(&val ,(int32_t*) arg, sizeof(val)) )
                        {
                                pr_err("Data Write : Err!\n");
                        }
                        pr_info("The var: %d\n",val); 
                        if(val == 1)
                        {
                        	*gpset_reg |= (0x1 << 26);
                		  pr_info("LED IS ON\n");
                	}
                	else
                	{
        			*gpclr_reg |= (0x1 << 26);
                		pr_info("LED IS OFF\n");
                	}			          	                                          
                        break;
            }
        return 0;
}
static void __exit gpio_driver_exit(void)
{
	unsigned int pin = 26;
	printk("Leaving my driver!\n");

        cdev_del(&mycdev);
	unregister_chrdev_region(devno , 1);
	device_destroy(ptr , devno);
	class_destroy(ptr);
        printk("driver unloaded\n");
	iounmap(gpio_registers);
	//proc_remove(lll_proc);
	return;
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bare metal programming");
MODULE_DESCRIPTION("Test of writing drivers for RASPI");
MODULE_VERSION("1.0");
