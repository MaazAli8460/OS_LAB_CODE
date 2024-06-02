#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std;

int main()
{
	int a,b,c,d,e,f,ab,cd,ef;
	cout<<"\nEnter a:";
	cin >> a;
	cout<<"\nEnter b:";
	cin >> b;
	cout<<"\nEnter c:";
	cin >> c;
	cout<<"\nEnter d:";
	cin >> d;
	cout<<"\nEnter e:";
	cin >> e;
	cout<<"\nEnter f:";
	cin >> f;
	
	int min,status,status2,status3;
	pid_t process_id_1=fork();

	if(process_id_1== 0)
	{
		int res; 	
		res=a*b;	
		exit(res);	
	}
	else
	{
		wait(&status);
		ab = WEXITSTATUS(status); 
		pid_t process_id_2=fork();
		if(process_id_2== 0)
		{
			int res; 	
			res=c/d;	
			exit(res);	
		}
		else
		{
			wait(&status2);
			cd = WEXITSTATUS(status2); 
			pid_t process_id_3=fork();
			if(process_id_3 == 0)
			{
				int res3; 	
				res3=e-f;	
				exit(res3);
			}
			else
			{
				wait(&status3);
				ef = WEXITSTATUS(status3);
				cout<<"\nA*B="<<ab;
				cout<<"\nC/D="<<cd;
				cout<<"\nE-F="<<ef;
				cout<<"\n(A*B) + (C/D) + (E-F)="<<ab+cd+ef;
			}
		}
		
	}
	
	
	
	return 0;
}
