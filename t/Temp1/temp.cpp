#include<iostream>
#include<unistd.h>
#include<sys/types.h>


using namespace std;

int main()
{

	if(fork() && fork() || fork())
	{
		fork();
		cout<<"$"<<endl;
	}
	cout<<"*";
	cout<<endl;
	return 0;
}

