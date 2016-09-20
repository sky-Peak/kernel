#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 int main(int arg,char *argv[])
{
  char a[100];
  int rt=0;
  int i=0;
  int j=0;
  char *b[100]={NULL};
  while(1)
 {
	printf("请输入命令：");
	gets(a);
	if(strcmp(a,"exit")==0)
	{
		 break;
	}
	i=0;
	j=0;
	while(a[i]!='\0')
	{       
		if(a[i]!=' '&&(i==0||a[i-1]=='\0'))
		{
  	  		b[j]=a+i;
		  	j++;
		}
 		if(a[i]==' ')
		{
	 		a[i]='\0';
		}
		i++;
	}
		if(fork()==0)
		{
 			 execvp(b[0],b);
		}	
	wait(&rt);
	memset(b,0,sizeof(b));
 }	
 return 0;
}
