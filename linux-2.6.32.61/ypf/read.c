#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int a;
	char s[100]="";
	a=open("/dev/ypf",O_RDONLY);
	read(a,s,6);
	close(a);
	printf("%s\n",s);
	return 0;
}
