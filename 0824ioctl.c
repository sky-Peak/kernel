#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "0824ypf.h"
int main(int argc,char **argv)
{
	int fd;
	int a;
	int b;
	int c;
	int sel;
	fd=open("/dev/yue_dev",O_RDWR);
	do{
	printf("请选择操作：1输入 2输出 3退出\nplease:");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		printf("please input:");
		scanf("%d",&b);
		ioctl(fd,CMD1,b);
		break;
	case 2:
		ioctl(fd,CMD2,&a);
		printf("a is:%d\n",a);
		break;
	case 3:
		close(fd);
		return 0;
	default :
		break;
	}
	}while(sel); 
	close(fd);
	return 0;
	
}
