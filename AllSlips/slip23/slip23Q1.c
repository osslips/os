#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
    int pid;
    pid=fork();
    if(pid>0)
    {
        printf("I am parent process and my id is:",getppid());
    }
    else if(pid==0)
    {
        printf("I am child process and my id is:",getpid());
        printf("My parent id before termination is:",getppid());
        sleep(5);
        printf("My parent id after termination is:",getppid());
    }
    else
    {
        printf("The process is unsuccessful!");
    }
}
