/*
 *program to open a file using the open
 *
 */ 
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main()
{
	int fd;
	fd = open("temp",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	cout<<"file opened with fd "<<fd<<endl;
	close(fd);
}
