/*
 * pipe
 * create the pipe
 * write data into the pipe 
 * read data from the pipe
 *
 * */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd[2];
	if(pipe(fd)<0)
	{
		perror("pipe");
		return 0;
	}
	printf("fd[0] = %d fd[1] = %d\n",fd[0],fd[1]);

	if(fork()==0)
	{
		char a[20];
		printf("child is writing to the pipe...:");
		scanf("%19[^\n]",a);
		write(fd[1],a,strlen(a)+1);
	}
	else
	{
		char b[20];
		printf("parent is reading from the pipe...\n");
		read(fd[0],b,sizeof(b));
		printf("parent read from the pipe = %s\n",b);

	}
}
