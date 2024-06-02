#include<iostream>
#include<algorithm>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	string str="Hello world";
	cout<<"\nOrignal string:"<<str;
	
	cout<<endl;
	reverse(str.begin(),str.end());
	cout<<"\nRev string:"<<str<<endl;
	
	return 0;
}
