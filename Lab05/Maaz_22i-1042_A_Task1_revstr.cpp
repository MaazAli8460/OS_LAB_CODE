#include<iostream>
#include<algorithm>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	string str="Hello world how are you.";
	cout<<"\nOrignal st:"<<str<<endl;
	reverse(str.begin(),str.end());
	cout<<"\nRev string:"<<str<<endl;
	char *args2[]={"./a2",nullptr};  //command
	execvp(args2[0],args2);
	perror("execvp");
	return 0;
}

