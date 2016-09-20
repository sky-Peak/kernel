#include <stdio.h>

int main()
{
 int i=0;
 int j=0;
 int *arr;
 int n=0;
 int p=0;

 printf("请输入对数：");
 scanf("%d",&n);

 n=2*n;
 printf("请输入数字：");
 for(i=0;i<n;++i)
 {
	scanf( "%d",&arr[i]);
 }
 i=0;
 j=n-1;
 while((i!=(n-1))&&(j!=0))
 {
	if(arr[i]==arr[j])
	{
		p++;
		i++;
		j--;
		arr[i]+=arr[i-1];
		arr[j]+=arr[j+1];
	}
	else if(arr[i]>arr[j])
	{
		j--;
		arr[j]+=arr[j+1];
	}
	else
	{
		i++;
		arr[i]+=arr[i-1];
 	}
 }

 printf("%d",p);
 return 0;
}
