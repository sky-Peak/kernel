#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include "0823ypf.h"
 struct stack
{
 struct miscdevice *demoled;
 int *p;
 int size;
 int i;
};
 struct stack  *stack;
int yue_open(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "this is open\n");
	return 0;
}
int yue_release(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "this is release\n");
	return 0;
}
static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
	if(cmd==CMD0)
	{
	 memset(stack->p,0,6*sizeof(int ));	
	 stack->i=0;
	 printk(KERN_INFO "this is CMD0\n");
	 return 0;
	}
	if(cmd==CMD1)
	{
		if(stack->i==stack->size)
		{
		 printk(KERN_INFO "stack full!\n");
		 return -1;
		}
		stack->p[stack->i]=(int)arg;
		(stack->i)++;
		printk(KERN_INFO "this is CMD1\n");
		return 0;
	}
	if(cmd==CMD2)
	{
		if(stack->i==0)
		{
		 printk(KERN_INFO "stack kong!\n");
		 return -1;
		}
		(stack->i)--;
		copy_to_user((int *)arg,(int *)(stack->p+stack->i),sizeof(int));
		printk(KERN_INFO "this is CMD2\n");
		return 0;
	}
		printk(KERN_INFO "this is CMD\n");
	return 0;
}

struct file_operations dev_fops={
        .owner  = THIS_MODULE,
        .unlocked_ioctl = ok6410_leds_unlocked_ioctl,
        .open   = yue_open,
        .release= yue_release,
};
static struct miscdevice demoled={
        .minor  = MISC_DYNAMIC_MINOR,
        .name   = DEVICE_NAME,
        .fops   = &dev_fops,
};

static int __init yue_init(void)
{
	stack=kzalloc(sizeof(struct stack),GFP_KERNEL);
	stack->size=6;
	stack->p=kzalloc(6*sizeof(int ),GFP_KERNEL);
	stack->i=0;
	stack->demoled=&demoled;
	misc_register(&demoled);
	printk(KERN_INFO "this is init\n");
	return 0;
}
static void __exit yue_exit(void)
{
	kfree(stack->p);
	kfree(stack);
	misc_deregister(&demoled);
	printk(KERN_INFO "this is exit\n");
	return ;
}
module_init(yue_init);
module_exit(yue_exit);
