/*
 *WRITEND
 *
 *
 * The fifo must be opened on both end reading and writing before data can be passed,
 * Normaly opening the fifo blocks untilt the other end is open
 *
 */
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	char a[20];
	mkfifo("f1",0644);
	printf("process Writing\n");
	printf("waiting for the read end to open...\n");
	fd = open("f1",O_WRONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	printf("Enter the message :");
	scanf("%19[^\n]",a);
	printf("%s\n",a);
	write(fd,a,strlen(a));
}
