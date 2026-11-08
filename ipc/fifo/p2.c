#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int fd;
	char a[20],b[20];
	mkfifo("f1",0644);
	printf("half duplex\n");
	printf("process-2\n");
	fd = open("f1",O_RDWR);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	printf("Enter the message to send....: ");
	scanf("%19[^\n]",b);
	if(write(fd,b,strlen(b)+1)<0)
	{
		perror("write");
		return 0;
	}
	printf("Waiting for messag to receive\n");
	if(read(fd,a,sizeof(a))<0)
	{
		perror("read");
		return 0;
	}
	printf("Messag from the process 1 is :%s\n",a);

}
