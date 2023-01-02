#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
    int pid,retnice;
    printf("press DEL to stop process\n");
    pid=fork();
    while(1)
    {
        if(pid==0)
        {
            retnice=nice(-5);
            printf("child gets higher CPU priority %d\n",retnice);
            sleep(1);
        }
        else
        {
            retnice=nice(4);
            printf("Parent gets lower CPU priority %d\n",retnice);
            sleep(1);      
        }
    }
}
