#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	int num1,num2;
	cout<<"\nEnter the first number:";
	cin >> num1;
	cout<<"\nEnter the second number:";
	cin >> num2;
	int child_status,min,status;
	pid_t process_id = fork();

	if(process_id == 0)
	{
		int res; 	
		if(num1>num2 )
			res = num2; 
		else	
			res = num1;
			
		exit(res);	
	}
	else
	{
		wait(&status);
		min = WEXITSTATUS(status); 
		cout<<"This is minimum:"<<min;	
		if(num1%2==0)//?cout<<"\nNum1 is even.":cout<<"\nNum1 is odd.";
		{
			cout<<"\nNum1 is even.";	
		}
		else
		{
			cout<<"\nNum1 is odd.";
		}
		if(num2%2==0)
		{
			cout<<"\nNum2 is even.";	
		}
		else
		{
			cout<<"\nNum2 is odd.";
		}
	}
	
	return 0;
}
