/*
 *READEND
 *
 * The fifo must be opened on both end reading and writing before data can be passed,
 * Normaly opening the fifo blocks untilt the other end is open
 *
 *
 */
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	char a[20];
	mkfifo("f1",0644);
	printf("process reading ..\n");
	fd = open("f1",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	printf("Waiting for message to receive...\n");
	read(fd,a,sizeof(a));
	printf("Recived message :%s\n",a);

}
