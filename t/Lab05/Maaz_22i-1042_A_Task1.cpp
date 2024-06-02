#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	char *args1[]={"./a1",nullptr};  
	execvp(args1[0],args1);
	perror("execvp");
	return 0;
}
