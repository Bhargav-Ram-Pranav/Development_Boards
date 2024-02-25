#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/printk.h>
#include<linux/timer.h>
#include<linux/ioport.h>
#include<asm/io.h>

#define base 0x3f200000

int *ptr;

int *temp;
int *temp1;

static int my_init(void)
{
	int j;
	unsigned long int t;

	ptr=ioremap(base,PAGE_SIZE);
	pr_info("base : %x\n",base);
	pr_info("ptr : %x\n",ptr);
	if(ptr==NULL)
	{
		pr_info("failed to get virtual address\n");
		return 0;
	}
	*ptr=0x0;
	*ptr= *ptr|(0x1<<15);
	temp=ptr+(0x1c / 0x4);
	temp1=ptr+(0x28 / 0x4);
	*temp=0x0;
	pr_info("temp : %x\n",temp);
	pr_info("temp1 : %x\n",temp1);
	for(j=0;j<5;j++)
	{
		pr_info("in loop\n");

		t=jiffies+msecs_to_jiffies(2000);
		do
		{
			pr_info("on\n");
			*temp=*temp|(0X1<<5);
		}while(jiffies<t);

		t=jiffies+msecs_to_jiffies(1000);
		do
		{
			pr_info("off \n");
			*temp1=*temp1|(0X1<<5);
		}while(jiffies<t);

	}
	*temp=*temp|(0X1<<5);
	pr_info("\n\n\nmodule loaded...\n\n\n");
	return 0;
}

static void my_exit(void)
{
	*temp1=*temp1|(0X1<<5);
	iounmap(ptr);
	pr_info("\n\n\nmodule unloaded...\n\n\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");





