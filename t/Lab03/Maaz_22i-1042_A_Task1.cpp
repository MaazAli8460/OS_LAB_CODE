#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	cout<<"\nThis is parent process."<<endl;
	int count=1;
	pid_t process_id = fork();

	if(process_id == 0)
	{
		cout<<"\nThis is child process:"<<count<<endl;
	}
	else
	{
		process_id=fork();
		count++;
		if(process_id == 0)
		{
			cout<<"\nThis is child process:"<<count<<endl;
		}
		
	}
	
	return 0;
}
