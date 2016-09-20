#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
 int i=0;
 int j=0;
 int n;
 int *arr;
 int p;

 printf("请输入剩余筷子的个数：");
 scanf("%d",&n);
 printf("请输入剩余各个筷子的长度：");
 arr=(int *)malloc(sizeof(int)*n);
 for(i=0;i<n;++i)
 {
	 scanf(" %d",&arr[i]); 
 }

 for(i=0;i<n;i++)
   {
	for(j=0;j<n-1-i;j++)
	{
	if(arr[j]>arr[j+1])
	{
		p=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=p;		
	}
	}   
   }
 	 i=0;

 while(i<n)
 {
 	if(arr[i]==arr[i+1])
	{
		i+=2;
	} 
	else
	{
		printf("丢失的筷子长短是：%d",arr[i]);
		return 0;
  	}
}
 	free(arr);
	 printf("-1");
	 return 0; 
}
