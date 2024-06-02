#include<iostream>
#include<algorithm>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main()
{
	string str1="Hello world";
	cout<<"\nOrignal:"<<str1<<endl;
    	int s1=str.size(); 
    	for (int i=0;i<s1;i++)
    	{
        	if (islower(str1[i]))
        	{
        	    str1[i]= char(toupper(str1[i]));
        	}
    	}
	cout<<"\nCaps str:"<<str1<<endl;
	
	return 0;
}
