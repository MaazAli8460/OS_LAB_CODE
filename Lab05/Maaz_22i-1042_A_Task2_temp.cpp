#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main(int argc,char* argv[])
{
	cout<<"\nThis is child process."<<endl;
	for(int i=0;i<argc;i++)
	cout<<argv[i]<<endl;
	
	return 0;
}
