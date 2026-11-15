/*
 *program to prove that fd0 is associated with the stdin buffer
 *
 */
#include<stdio.h>
#include<unistd.h>
int main()
{
	char ch;
	int i=0;
	while(1)
	{
		printf("Enter the cahracter...");
		scanf(" %c",&ch);
		printf("ch = %c\n",ch);
		i++;
		if(i==3)
		{
			printf("stdin is closed....\n");
			close(0);
		}
	}
}
