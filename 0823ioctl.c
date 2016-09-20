#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "0823ypf.h"
int main(int argc,char **argv)
{
	int fd;
	int a;
	fd=open("/dev/yue_dev",O_RDWR);
	
	ioctl(fd,CMD0);
	ioctl(fd,CMD1,1);
	ioctl(fd,CMD1,2);
	ioctl(fd,CMD1,3);
	ioctl(fd,CMD1,4);
	ioctl(fd,CMD2,&a);
	printf("a is:%d\n",a);
	ioctl(fd,CMD2,&a);
	printf("a is:%d\n",a);
	ioctl(fd,CMD2,&a);
	printf("a is:%d\n",a);
	close(fd);
	return 0;
	
}
