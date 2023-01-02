#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void bubblesort(int arr[30], int n)
{
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertionsort(int arr[30], int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<=arr[j])
        {
            arr[j+1]==arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}

void main()
{
    int arr[25], arr[25], n, i, status;
    printf("\nEnter the number of values in array:");
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int pid=fork();
    if(pid==0)
    {
        sleep(2);
        printf("\nchild process\n");
        printf("child process id=%d\n",getpid());
        insertionsort(arr, n);
        printf("\nElements sorted using insertionsort:");
        printf("\n");
        for(i=0; i<n; i++)
            printf("%d",&arr[i]);
        printf("\b");
        printf("\nparent process id=%d\n",getppid());
    }
    else
    {
        printf("\nparent process\n");
        printf("parent process id=%d\n",getpid());
        bubblesort(arr, n);
        printf("Elements sorted using bubblesort:");
        printf("\n");
        for(j=0; j<n; j++)
            printf("%d",&arr[j]);
        printf("\n\n\n");
    }
}