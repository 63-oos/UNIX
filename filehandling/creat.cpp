/*
 *
 * program to create a file using the creat
 *
 */ 
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main()
{
	int fd;
	fd = creat("temp",0644);
	if(fd==-1)
	{
		perror("creat");
		return 0;
	}
	cout<<"The file has been created with the fd "<<fd<<endl;
	close(fd);
}
