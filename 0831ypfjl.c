#include <stdio.h>
 
int main()
 {
    int M, S, T;
    int m = 0, t = 0;
    printf("请输入魔法.距离.时间：") ;
    scanf("%d%d%d",&M,&S,&T);
 
    if(S==0) 
	{
        printf("Yes:0\n"); 
        return 0;
	} 
   else if (T==0)
	 {
       		 printf("No:0\n"); 
       		 return 0;
    	 }
 
    while (m<S&&t<T) 
	{
        	if(M>=10)
		 {    
            		m+=60;
            		t++;
           		 M-=10;
       		 }
		 else if (M>=6&&T-t>=2&&S-m>34)
		 {  
            		m+=60;
            		t+=2;
           		 M-=6;  
       		 }
		 else if (M>=2&&T-t>=3&&S-m>51) 
		 {  
           		 m+=60;
           		 t+=3;
           		 M-=2;
        	 }
		 else if (T-t>=7&&S-m>=120) 
		{   
            		m+=120;
           		 t+=7;
        	}	
		 else
		 {    
            		int n1=T-t;
           		int n2=(S-m+16)/17;  
            		int n=n1<n2?n1:n2;
            		m+=n*17;
          		t+=n;
        	 }
    }
 
    if (m>=S)
    {
        printf("Yes:%d\n",t);
    }
    else
    {
        printf("No:%d\n",m);
    }
 
    return 0;
}
