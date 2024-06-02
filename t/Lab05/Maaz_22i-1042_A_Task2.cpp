#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	int count=1;
	pid_t process_id = fork();
	if(process_id == 0)
	{
		execl("./argsfile","Arg1","Arg2","Arg3",nullptr);
	}
	else
	{
		wait(NULL);
		cout<<"\nThe parent process finished."<<endl;
	}
	return 0;
}
