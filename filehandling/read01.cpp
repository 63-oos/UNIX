/*
 *
 * program to read the string from the file
 *
 *
 */ 
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main()
{
	int fd,ret;
	char arr[50];
	fd = open("temp",O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	ret = read(fd,arr,sizeof(arr));
	arr[ret] = '\0';
	if(ret<=0)
	{
		perror("read");
		return 0;
	}
	cout<<"data from the file is : "<<arr;
}
