#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string>

using namespace std;

int main(int argc,char* argv[])
{
	cout<<"\nThis is child process."<<endl;
	int sum1=0;
	cout<<"\nThe args recived:"<<argv[0]<<endl;
	int var=stoi(argv[0]);
	for(int i=1;i<=var;i++)
	sum1 = sum1 + i;	
	return sum1;
}
