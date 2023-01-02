#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
//#include <bfd.h>
char comm[100],*ptr;
char *args[10];
int tot_arg;

int typeline( char *option, char *fname);

main()
{
	do
	{
		printf("myshell $ ");
		getcomm();
		sep_arg();
		take_action();
	}while(1);
} // main

sep_arg()
{
	int i,j;
	i = j = tot_arg = 0;

	args[tot_arg] = (char*)malloc(sizeof(char) * 20);
	for(i=0; comm[i] !='\0' ; i++)
	{
		if( comm[i] == ' ')
		{
			args[tot_arg][j] = '\0';
			tot_arg++;
			args[tot_arg] = (char*)malloc(sizeof(char) * 20);	
			j=0;
		}
		else
		{
			args[tot_arg][j] =comm[i];
			j++;
		}
	} // while
	args[tot_arg][j] = '\0'; // complete last word
 	return;
}

getcomm()
{
	int len;
	ptr = fgets(comm,80,stdin);
	len = strlen(comm);
	comm[len-1] = '\0';
	return;
} // getcomm

take_action()
{
	char str[100];
	pid_t   pid;
	int status;

	if(strcmp(args[0],"search") == 0 )
		search(*args[1],args[2],args[3]);
	else
	if(strcmp(args[0],"count") == 0 )
		count(*args[1],args[2]);
	else
	if(strcmp(args[0],"typeline") == 0 )
		typeline(args[1],args[2]);
	else
	if(strcmp(args[0],"list") == 0 )
		list(*args[1],args[2]);
	else
	{	
		if( ptr == NULL )
			exit(0);
		if ( strlen(comm) <= 1 )
			return;
		if( ( pid = fork() ) < 0 )
		{
			printf("\nUnable to create process");
		}
		else
		if(  pid == 0 ) // child
		{   sscanf(comm,"%s",comm);
			execvp(comm,args);
			strcpy(str,"./");
			strcat(str,args[0]);
			execvp(str,args);
			printf("\n%s : command not found",comm);
			exit(0);
		}
		else //parent
		 waitpid(pid,&status,0);
	} // else
}// take action

int typeline( char *option, char *fname) 
{
	FILE *fp;
	int tot_lines,ch,n,cnt;
	//---- count the lines
	fp= fopen(fname,"r");
	if( fp == NULL )
	{
		printf("\nUnable to open file");
		exit(0);
	}
	tot_lines = 0;//count total lines
	ch = fgetc(fp);
	while ( ch != EOF )
	{
		if( ch == 10 ) //new line char
		tot_lines++;
		ch = fgetc(fp);
	}
	fclose(fp);
	//---- take action
	if( strcmp(option,"a")== 0 ) // print all lines
	{
		fp= fopen(fname,"r");
		ch = fgetc(fp);
		while ( ch != EOF )
		{
			printf("%c",ch);
			ch = fgetc(fp);
		}
		fclose(fp);
	}
	else
	{
		printf("\nInvalid option");
		exit(0);
	}
	return(0);
}
