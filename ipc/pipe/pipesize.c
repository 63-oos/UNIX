/*
 * pipe size
 * no child process 
 * writing only on the fd[1] until the pipe is full
 * no reading from the fd[0]
 *
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd[2],cnt = 0;
	char ch = 'a';
	if(pipe(fd)<0)
	{
		perror("pipe");
		return 0;
	}
	printf("sizeof pipe...\n");
	while(1)
	{
		if(write(fd[1],&ch,1)>0)
			cnt++;		
		printf("pipe size = %d\n",cnt);
	}
}
