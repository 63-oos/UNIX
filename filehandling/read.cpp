/*
 *
 * programe to read the data from the file...
 *
 */ 
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main()
{
	int fd,ret;
	char ch;
	fd = open("temp",O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		return 0;
	}
	cout<<"file opened sucessfully....fd = "<<fd<<endl;
	/*ret = read(fd,&ch,1);
	if(ret<=0)
	{
		perror("read");
		return 0;
	}
	cout<<"reading data from the file "<<ch<<endl;*/
	cout<<"reading data from the file :";
	while((ret = read(fd,&ch,1))>0)
	{
		cout<<ch;
	}
}
