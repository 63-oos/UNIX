#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
	int fd;
	char a[20],b[20];
	mkfifo("f1",0644);
	printf("half duplex\n");
	printf("process-1\n");
	fd = open("f1",O_RDWR);
	if(fd<0)
	{
		perror("opem");
		return 0;
	}
	printf("Waiting for the message from the process 2\n");
	if(read(fd,a,sizeof(a))<0)
	{
		perror("read");
		return 0;
	}
	printf("Message from process 2 : %s\n",a);
	printf("Enter the mesage to send : ");
	scanf("%19[^\n]",b);
	if(write(fd,b,strlen(b)+1)<0)
	{
		perror("write");
		return 0;
	}

}
