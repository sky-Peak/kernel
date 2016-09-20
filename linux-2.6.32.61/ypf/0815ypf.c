#include<linux/init.h>
#include<linux/module.h>
 static int n = 10;
 module_param(n,int,S_IRUGO);
 MODULE_AUTHOR ("ypf");
static int __init ypf_y(void)
{
 int i;
 for(i=0;i<n;i++)
 {
  printk(KERN_INFO "this is init\n");
 }
return 0;
}
static void __exit ypf_p(void)
{
 printk(KERN_INFO "this is exit\n");
}
module_init(ypf_y);
module_exit(ypf_p);
MODULE_LICENSE ("Dual BSD/GPL"); 
