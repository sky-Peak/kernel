#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
FILE * fp_out;
int count = 1;
char buf[80]="";

fp_out = fopen("mypipe", "w");
if (fp_out == NULL)
{
printf("Error opening pipe.\n");
exit(1);
}
do
{
printf("input:");
gets(buf);
//sprintf(buf,"This is test data for the named pipe example\n");
fwrite(buf, 1, 80, fp_out);
fflush(fp_out);
}while(strcmp(buf,"quit")!=0);
fclose(fp_out);
return 0;
} 
