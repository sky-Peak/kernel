#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int a;
	char s[]="iloveulalala12345698765432123";
	a=open("/dev/ypf",O_WRONLY);
	write(a,s,sizeof(s));
	close(a);
	return 0;
}
