#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        printf("I am child process and my id is: %d",getpid());
    }
    else if(pid>0)
    {
        printf("I am parent process and my id is: %d",getppid());
    }
    else
    {
        printf("The process is unsuccessful!");
    }
}
