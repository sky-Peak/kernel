#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/semaphore.h>
#include "ypf.h"
//#define N 10
 static int N = 10;
 module_param(N,int,S_IRUGO);
 struct mydev
{
 struct miscdevice *demoled;
 struct semaphore sem;
 int *data;
 int count;
 int size;
 int i;
 int j;
};
 struct mydev  *mydev;
int yue_open(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "this is open\n");
	if(down_interruptible(&(mydev->sem)))
	{
		return ERESTARTSYS;
	}
	return 0;
}
int yue_release(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "this is release\n");
			 up(&(mydev->sem));
	return 0;
}
static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
	if(cmd==CMD1)
	{
//	 	down_interruptible(&(mydev->sem));
		if(mydev->count<mydev->size)
		{
			 mydev->data[mydev->i]=(int)arg;
			 (mydev->i)++;
		if(mydev->i==mydev->size)
		{
			 (mydev->i)=0;
		}
			 (mydev->count)++;
	 		 printk(KERN_INFO "this is cmd1\n");	 
//			 up(&(mydev->sem));
			 return 1;
	 	}
//			 up(&(mydev->sem));
		  return 0;	
	}
	if(cmd==CMD2)
	{
//	 down_interruptible(&(mydev->sem));
	 if(mydev->count>0)
	{
		copy_to_user((int *)arg,(int *)(mydev->data+mydev->j),sizeof(int));
		(mydev->j)++;
		if(mydev->j==mydev->size)
		{
		 	mydev->j=0;
		}
			(mydev->count)--;
//			 up(&(mydev->sem));
		return 1;	
	}
	else{return -1;}
	 printk(KERN_INFO "this is cmd2\n");	 
//			 up(&(mydev->sem));
	 return 0;
	}
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
	mydev=kzalloc(sizeof(struct mydev),GFP_KERNEL);
	mydev->data=kzalloc(N * sizeof(int),GFP_KERNEL);
	mydev->size=N;
	mydev->i=0;
	mydev->j=0;
	mydev->count=0;
	sema_init(&(mydev->sem),1);
	mydev->demoled=&demoled;
	misc_register(&demoled);
	printk(KERN_INFO "this is init\n");
	return 0;
}
static void __exit yue_exit(void)
{
	kfree(mydev->data);
	kfree(mydev);
	misc_deregister(&demoled);
	printk(KERN_INFO "this is exit\n");
	return ;
}
module_init(yue_init);
module_exit(yue_exit);
