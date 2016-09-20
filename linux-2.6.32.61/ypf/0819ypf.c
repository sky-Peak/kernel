#include<linux/init.h>
#include<linux/module.h>
#include <linux/kernel.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/types.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
 dev_t dev_id;
 struct mydev
{
 struct cdev cdev;
 char *p;
 int n;
 loff_t r_i;
 loff_t w_i;
};
 struct mydev *mydev;
 int yue_open(struct inode * inode,struct file * filp)
{
        struct mydev *pmydev=NULL;
        printk(KERN_INFO "this is open.\n");
        pmydev=container_of(inode->i_cdev,struct mydev,cdev);
        filp->private_data=pmydev;
        return 0;

}
 int yue_release(struct inode *inode,struct file *filp)
{
 printk(KERN_INFO "this is release\n");
 return 0;
}
 ssize_t yue_write(struct file *filp,const char __user *buff,size_t count,loff_t*lofp)
{
        struct mydev *pmydev=NULL;
        pmydev=(struct mydev *)(filp->private_data);
        copy_from_user(pmydev->p+pmydev->w_i,buff,count);
        printk(KERN_INFO "Call demo_write.:%lu\n",count);
        mydev->w_i+=count;
        return count;
}
 ssize_t yue_read(struct file *filp,char __user *buff,size_t count,loff_t*lofp)
{
        struct mydev *pmydev=NULL;
        pmydev=(struct mydev *)(filp->private_data);
        copy_to_user(buff,pmydev->p+pmydev->r_i,count);
        printk(KERN_INFO "Call demo_read:%lu\n",count);
        pmydev->r_i+=count;
        return count;
}
 struct file_operations fops={
	.owner	=	THIS_MODULE,
	.open	=	yue_open,
	.release=	yue_release,
	.write	=	yue_write,
	.read	=	yue_read,
};
 static int __init yue_init(void)
{
 int err=0;
 printk(KERN_INFO "this is init\n");
 alloc_chrdev_region(&dev_id,0,4,"yue_dev");
 mydev=kmalloc(sizeof(struct mydev),GFP_KERNEL);
 if(mydev==NULL)
        {
                printk(KERN_INFO "Error: alloc mydev fail!\n");
                goto FAIL1;
        }

 memset(mydev,0,sizeof(struct mydev));
 cdev_init(&(mydev->cdev),&fops);
 mydev->cdev.owner=THIS_MODULE;
 mydev->p=kmalloc(100,GFP_KERNEL);
  if(mydev->p==NULL)
        {
                printk(KERN_INFO "mem alloc fail\n");
                goto FAIL2;
        }

 memset(mydev->p,0,100);
 err=cdev_add(&(mydev->cdev),dev_id,1);
 if(err)
        {
                printk(KERN_NOTICE "Error :dding yue_dev.");
                goto FAIL3;
        }
 
 mydev->w_i=0;
 mydev->r_i=0;
 return 0;
        FAIL3:
                kfree(mydev->p);
        FAIL2:
                kfree(mydev);
        FAIL1:
                unregister_chrdev_region(dev_id,4);
                printk(KERN_NOTICE "Error :  adding yue_dev.");

                return -1;

} 
static void __exit yue_exit(void)
{
 cdev_del(&(mydev->cdev));
 kfree(mydev->p);
 kfree(mydev);
 unregister_chrdev_region(dev_id,4);
 printk(KERN_INFO "this is exit\n");
 return ;
}
module_init(yue_init);
module_exit(yue_exit);
