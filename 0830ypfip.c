#include <stdio.h>
#include <stdlib.h>
 int ip(int a,int b, int c,int d)
{
  int m;
 	scanf("%d.%d.%d.%d",&a,&b,&c,&d);
	if((a>255)||(b>255)||(c>255)||(d>255)||(a==127)||(a==255)||(a==0))
	{
		return 0;
	}
/*	if(a=127&&b==0&&c==0&&d==1)
	{
		rerurn 1;
	}*/
	m=(a<<24)|(b<<16)|(c<<8)|d;
	return m;
}

 int zw(int a, int b,int c,int d)
{
 int n;
	scanf("%d.%d.%d.%d",&a,&b,&c,&d);
	if((a==255&&b==255&&c==255&&d==255)||(a==0&&b==0&&c==0&&d==0))
	{
		return 0;
	}
	if((a==255&&(b==255||b==254||b==252||b==248||b==224||b==192||b==128||b==1||b==0)&&(c==0)&&(d==0))||((a==248||a==254||a==252||a==224||a==192||a==128)&&(b==0)&&(c==0)&&(d==0))||(a==255&&b==255&&(c==255||c==254||c==252||c==248||c==240||c==224||c==192||c==128)&&d==0)||(a==255&&b==255&&c==255&&(d==0||d==128||d==192||d==248||d==224||d==240||d==252||d==254))||(a==1&&b==0&&c==0&&d==0))
	{
		n=(a<<24)|(b<<16)|(c<<8)|d;
		return n;
 	}
	else 
	{
		return 1;
	}
		n=(a<<24)|(b<<16)|(c<<8)|d;
		return n;
	return n;
}
 int yu(int ip,int zw)
{
 	int a;
	a=(ip&zw);
	return a;
}
int main()

{ 
 int q;
 int i=0;
 int arr1;
 int arr2;
 int arr3;
 int arr4;
 int m;
 int n;
 int h;
 int a;
 int b;
 int c[100];
 int w1,w2,w3,w4;
 int e1,e2,e3,e4;
 printf("请输入IP地址：");
 m=ip(arr1,arr2,arr3,arr4);
 if(m==0)
 {
	printf("Invalid IP adress. \n");
	return 0;
 }
 printf("请输入子网掩码：");
 n=zw(arr1,arr2,arr3,arr4);
 if(n==0||n==1)
 {
	printf("Invalid netmask adress. \n");
	return 0;
 }
 h=yu(m,n);
 printf("请输入后面共有几个同学：");
 scanf("%d",&q);

 for(i=1;i<q+1;i++)
 {
	printf("请输入第%d个同学IP地址：",i);
	a=ip(w1,w2,w3,w4);
	 if(a==0)
	 {
		printf("输入有误！\n");
		return 0;
	 }
 	printf("请输入第%d个同学的子网掩码：",i);	
	b=zw(e1,e2,e3,e4);
	 if(b==0||b==1)
	 {
		printf("输入有误！\n");
		return 0;
	 }
 	c[i]=yu(a,b);
 }
 i=1;
  for(i=1;i<q+1;i++)
 {
	if(h==c[i])
	{
		printf("与第%d:let's rock\n",i);
	}
	else
   	{
		printf("与第%d:not you\n",i);
	} 
 } 
 return 0;
}
