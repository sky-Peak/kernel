#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
int main()
{
FILE * fp_in;
int count = 1;
char buf[80]="";
int flag_exit=0;
fp_in = fopen("mypipe", "r");//管道mypipe已经存在
if (fp_in == NULL) {
printf("Error in fdopen.\n");
exit(1);
}
do
{
while((count = fread(buf, 1, 80, fp_in))>0)
{
if(strcmp(buf,"quit")==0)
{
flag_exit=1;
}
printf("received from pipe: %s\n", buf);
fflush(fp_in);
}
}while(flag_exit==0);
fclose(fp_in);
return 0;
} 
