#include <stdio.h>

 int main()
{
 int M,S,T;
 int m,n,a;
 printf("请输入魔法值，距离，时间：");
 scanf("%d%d%d",&M,&S,&T);
 m=0;
 n=0;

 if(S==0)
 {
	printf("Yes,0\n");
 }
 else if(T==0)
 {
	printf("No,0\n");
 }
 else if(M>=10)
 {
 m=(M/10)*60;
 n=M/10;
 a=M%10;
 while(m<S&&n<T)
 {
        if(10>a>=6)
        {
                if(60>S-m>17)
                {
     printf("11\n");
		         n+=2;
                        m+=60;
                }
                else if(S-m<17)
                {
     printf("12\n");
                        n+=1;
                        m+=17;
                }
        }
        else if(6>a>2)
        {
                if(102>=S-m>60)
                {
     printf("13\n");
                        n+=(S-m)/17;
                        m+=(S-m);
                }
                else if(120>=S-m>102)
                {
     printf("14\n");
                        n+=7;
                        m+=120;
                }
        }
        else if(2>a>=0)
        {
                if(S-m==120)
                {
     printf("15\n");
                        n+=7;
                        m+=120;
                }
                else if(102<S-m<=119)
                {
     printf("16\n");
                        n+=7;
                        m+=119;
                }
                else if(S-m<102)
                {
     printf("17\n");
                        n+=(S-m+16)/17;
                        m+=(S-m);
                }
        }
  printf("++++++++++++++\n");
 }
  printf("---------------------\n");
 if(m>=S)
 {
        printf("Yes:%d\n",n);
        return 0;
 }
else if (m<S)
 {
        printf("No:%d\n",m);
        return 0;
 }

 }
m=0;
n=0;
  if(M<10) 
{
while(m<S&&n<T)
 {
        if(10>M>=6)
        {
                if(60>S-m>17)
                {
     printf("21\n");
                        n+=2;
                        m+=60;
                }
                else if(S-m<17)
     printf("22\n");
                {
                        n+=1;
                        m+=17;
                }
        }
        else if(6>M>2)
        {
                if(102>=S-m>60)
                {
     printf("23\n");
                        n+=(S)/17;
                        m+=(S);
                }
                else if(120>=S-m>102)
                {
     printf("24\n");
                        n+=7;
                        m+=120;
                }
        }
        else if(2>M>=0)
        {
                if((S-m)==120)
                {
 printf("25\n"); 
                        n+=7;
                        m+=120;
                }
                else if(102<(S-m)<=119)
                {
     printf("26\n");
  
                        n+=7;
                        m+=119;
                }
                else if((S-m)<=102)
                {
     printf("27\n");
                        n=n+((S-m)/17);
                        m+=S-m;
                }
        }
 printf("______________________\n"); 
}
 if(m>=S)
 {
	printf("Yes:%d\n",n);
	return 0;
 }
else if (m<S)
 {
	printf("No:%d\n",m);
	return 0;
 }
 
}

 return 0;
}
