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
	int status1,status2;
	if(process_id == 0)
	{
		char *args[]={"./Q3_sumproc","5",nullptr};
		execl(args[0],"8",nullptr);
	}
	else
	{
		wait(&status1);
		int result=WEXITSTATUS(status1);
		cout<<"\nsum from 1 to 8="<<result<<endl;
		pid_t process_id1 = fork();
		int status;
		if(process_id1 == 0)
		{
			char *args[]={"./Q3_sumproc","20",nullptr};
			execl(args[0], "20",nullptr);
		
		}
		else
		{
			wait(&status2);
			int result1=WEXITSTATUS(status2);
			cout<<"\nsum from 1 to 20="<<result1<<endl;
		}
		
	}
	
	return 0;
}
