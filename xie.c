#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ypf.h"
 int main(int argc,char **argv)
{
 int fd;
 int a;
 int b;
 fd=open("/dev/yue_dev",O_RDWR);
 for(a=0;a<100;a++)
 {
  b=ioctl(fd,CMD1,a*5);
  printf("io:%d\n",b);
 }
 close(fd);
 return 0;
} 
