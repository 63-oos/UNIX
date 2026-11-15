/*
 * programe to prove that fd 1(file descriptor 1 )is associated with stdout buffer 
 *
 */ 
#include<stdio.h>
#include<unistd.h>
int main()
{
	int i=0;
	while(1)
	{
		printf("Hello\n");
		sleep(2);
		if(i==3)
		{
			printf("stdout is closed....\n");
			close(1);
		}
		i++;
	}
}
