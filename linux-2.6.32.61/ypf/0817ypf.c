#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/types.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
 dev_t dev_id;
 struct mydev
{
 struct cdev *cdev;
 char *data;
 int count;
 loff_t w_i;
 loff_t r_i;
};
 struct mydev *mydev;
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
 ssize_t yue_read(struct file *filp,char __user *buff,size_t count,loff_t *lofp)
{
 printk(KERN_INFO "this is read\n");
 copy_to_user(buff,mydev->data+mydev->r_i,count);
 mydev->r_i+=count;
 return 0;
}
 ssize_t yue_write(struct file *filp,const char __user *buff,size_t count,loff_t *lofp)
{
 printk(KERN_INFO "this is write\n");
 copy_from_user(mydev->data+mydev->w_i,buff,count);
 mydev->w_i+=count;
 return 0;
}
 struct file_operations fop={
	.owner	=THIS_MODULE,
	.open	=yue_open,
	.release=yue_release,
	.read	=yue_read,
	.write	=yue_write,
};
 static int __init yue_init(void)
{
 alloc_chrdev_region(&dev_id,0,4,"yue_dev");
 mydev=kmalloc(sizeof(struct mydev),GFP_KERNEL);
 memset(mydev,0,sizeof(struct mydev));
 mydev->cdev=cdev_alloc();
 cdev_init(mydev->cdev,&fop);
 mydev->cdev->owner=THIS_MODULE;
 mydev->data=kmalloc(100,GFP_KERNEL);
 memset(mydev->data,0,100);
 cdev_add(mydev->cdev,dev_id,1);
 printk(KERN_INFO "this is init\n");
 mydev->r_i=0;
 mydev->w_i=0;
 return 0;
}
 static void __exit yue_exit(void)
{
 cdev_del(mydev->cdev);
 kfree(mydev->data);
 kfree(mydev);
 unregister_chrdev_region(dev_id,4);
 printk(KERN_INFO "this is exit\n");
 return;
}
module_init(yue_init);
module_exit(yue_exit);
