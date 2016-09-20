#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ypf.h"
 int main(int argc,char **argv)
{
 int fd;
 int *a;
 int b;
 int i=0;
// int rt;
	 fork();
	 fork();
	 fd=open("/dev/yue_dev",O_RDWR);
	for(i=0;i<25;i++) 
	{
	if( ioctl(fd,CMD2,&a)==1)
 	{
 	 printf("%d:%d\n",getpid(),a);
	}
	else
	{
		printf("读取失败！");
	}
	}
  //wait(&rt);
  close(fd);
 return 0;
} 
