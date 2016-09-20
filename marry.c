#include<stdio.h>
int main()
{
	int n;
	int *a;
	int i=0;
	int j,k;
	int q;
	int p=0;
	printf("输入对数：");
	scanf("%d",&n);
	printf("输入地面鸽子数字：");
	n=2*n;
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	i=0;
	j=a[0];
	k=a[n-1];
	p=0;
	q=n-1;
//	do
	while((p<=n)&&(q>=0))
	{
		if(j==k)
		{
			i++;
			j+=a[p+1];
			k+=a[q-1];
			p++;
			q--;
//			printf("j=k\n");
//			printf("%d\t%d\t",p,q);
//			printf("%d\t%d\n",j,k);
		}
		else if(j>k)
		{
			k+=a[q-1];
			q--;
//			printf("%d\t%d\t",p,q);
//			printf("%d\t%d\n",j,k);
		}
		else 
		{
			j+=a[p+1];
			p++;
//			printf("%d\t%d\t",p,q);
//			printf("%d\t%d\n",j,k);
		}
	}//while((p<(n))&&(q!=0));

	printf("%d\n",i);
	return 0;
}
