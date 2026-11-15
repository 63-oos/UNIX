/*
 *program to prove that the fd1 is associated witht the stdout buffer
 *
 *
 */ 
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	int i=0;
	while(1)
	{
		cout<<"hello"<<endl;
		sleep(2);
		i++;
		if(i==3)
		{
			cout<<"stdout is closed...."<<endl;
			close(1);
		}
	}
}
