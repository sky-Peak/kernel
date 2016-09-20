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
 char * data[4];
 int i;
 loff_t r_i[4];
 loff_t w_i[4];
};
 struct mydev *mydev;
 int yue_open(struct inode *inode,struct file *filp)
{
  struct mydev *pmydev;
  pmydev=container_of(inode->i_cdev,struct mydev ,cdev);
  pmydev->i=(inode->i_rdev&0xfffff);
  printk(KERN_INFO "dev_t:%x",pmydev->i);
  filp->private_data=pmydev;
  printk(KERN_INFO "this is open\n");
  return 0;
}
 int yue_release(struct inode *inode,struct file *filp)
{
 printk(KERN_INFO "this is release\n");
 return 0;
}
 ssize_t yue_write(struct file *filp,const char  __user *buff,size_t count,loff_t *lofp)
{
 struct mydev *pmydev=NULL;
 int i;
 pmydev=(struct mydev *)(filp->private_data);
 i=pmydev->i;
 copy_from_user(pmydev->data+pmydev->w_i[i],buff,count);
 pmydev->w_i[i]+=count;
 printk(KERN_INFO "this is write\n");
 return count;
}
 ssize_t yue_read(struct file *filp, char __user *buff,size_t count, loff_t *lofp)
{
 struct mydev *pmydev=NULL;
 int i;
 pmydev=(struct mydev *)(filp->private_data);
 i=pmydev->i;
 copy_to_user(buff,pmydev->data+pmydev->r_i[i],count);
 pmydev->r_i[i]+=count;
 printk(KERN_INFO "this is read\n");
 return count;
}
 struct file_operations fops={
	.owner=THIS_MODULE,
	.open=yue_open,
	.release=yue_release,
	.write=yue_write,
	.read=yue_read,
};
 static int __init yue_init(void)
{
 int err=0;
 int i;
 printk(KERN_INFO "this is init\n");
 alloc_chrdev_region(&dev_id,0,4,"yue_dev");
 mydev=kzalloc(sizeof(struct mydev),GFP_KERNEL);
 if(mydev==NULL)
 {
   printk(KERN_INFO "mydev is NULL\n");
   goto FAIL1;
 }
 cdev_init(&(mydev->cdev),&fops);
 mydev->cdev.owner=THIS_MODULE;
 for (i=0;i<4;i++)
{
  mydev->data[i]=(char*)kzalloc(100,GFP_KERNEL);

 if(mydev->data==NULL)
 {
  printk(KERN_INFO "mydev->data is NULL\n");
  goto FAIL2;
 }
 mydev->r_i[i]=0;
 mydev->w_i[i]=0;
}
 err=cdev_add(&(mydev->cdev),dev_id,4);
 if(err)
 {
  printk(KERN_INFO "err is %d\n",err);
  goto FAIL3;
 }
 return 0;
        FAIL3:
                kfree(mydev->data);
        FAIL2:
                kfree(mydev);
        FAIL1:
                unregister_chrdev_region(dev_id,4);
        return -1    ;
}
 void __exit yue_exit(void)
{
 kfree(mydev);
 kfree(mydev->data);
 cdev_del(&(mydev->cdev));
 unregister_chrdev_region(dev_id,4);
 printk(KERN_INFO "this is exit\n");
} 
module_init(yue_init);
module_exit(yue_exit);
