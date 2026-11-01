/*
 * Finding the size using pipe2  function
 *
 * 
 */
#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int fd[2],cnt=0;
	char ch = 'a';
	if(pipe2(fd,O_NONBLOCK)<0)
	{
		perror("pipe2");
		return 0;
	}
	while(1)
	{
		if(write(fd[1],&ch,1)>0)
			cnt++;
		else
			break;
	}
	printf("pipe size = %d\n",cnt);
}
