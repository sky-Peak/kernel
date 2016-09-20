#ifndef __DEMO_H
#define __DEMO_H
#include<linux/ioctl.h>
#define DEVICE_NAME "yue_dev"
unsigned int CMD0=_IO(1,0);
unsigned int CMD1=_IOW(1,1,int);
unsigned int CMD2=_IOR(1,2,int *);
#endif
