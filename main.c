#include <stdio.h>
#include <unistd.h>
 int main()
 {
 int a;
  a=fork();
  if(a==0)
  {
	execl("./test","test","b",NULL);
  }
 else
  {
	execl("./test","test","a",NULL);
  }
  return 0; 
}
   
