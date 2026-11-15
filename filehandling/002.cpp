/*
 *
 *program to prove that the fd0 is assoiated with the stdin buffer
 *
 */ 
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	int i=0;
	char ch;
	while(1)
	{
		cout<<"Enter the character...: ";
		cin>>ch;
		cout<<"ch = "<<ch<<endl;
		i++;		
		if(i==3)
		{
			cout<<"stdin is closed..."<<endl;
			close(0);
		}
	}
}
