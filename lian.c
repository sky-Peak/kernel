  #include <stdio.h>
  #include <unistd.h>
 #include <string.h> 
 #include<stdlib.h>
#define INPUT 0
#define OUTPUT 1

int main()
 {
        int fd[2];
        /*定义子进程号 */
        pid_t pid;
        char buf[256]="";
        int returned_count;
        /*创建无名管道*/
        pipe(fd);
        /*创建子进程*/
        if((pid = fork()) == -1) {
                printf("Error in fork\n");
                exit(1);
        }
        /*执行子进程*/
        if(pid == 0) {
                printf("%d:in the spawned (child) process...\n",getpid());
                /*子进程向父进程写数据，关闭管道的读端*/
                close(fd[INPUT]);
                write(fd[OUTPUT], "test data", strlen("test data"));
                exit(0);
        } else {
                /*执行父进程*/
                printf("%d:in the spawning (parent) process...\n",getpid());
                /*父进程从管道读取子进程写的数据，关闭管道的写端*/
                close(fd[OUTPUT]);
                returned_count = read(fd[INPUT],buf,sizeof(buf));
                printf("%d:%d bytes of data received from spawned process: %s\n",getpid(),
                returned_count,buf);
		/*close( filedes[0] );  
        	 close( filedes[1] ); */
        }
//	waitpid( pid, NULL, 0 );    
     return 0;
}
