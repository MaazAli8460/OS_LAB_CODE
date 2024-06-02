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
	
	int min,status,status2,status3,s1,s2;
	pid_t process_id_1=fork();

	if(process_id_1== 0)
	{
	  int f3 = fork();
	  if (f3==0)
	  {
	  
	  	int f4 = fork();
	  	if (f4==0)
	  	{
	  		int res = e - f;
	  		ef=res;
	  		exit(res);
	  	
	  	}
	  	else
	  	{
	  		wait(&s1);
	  		ef = WEXITSTATUS(s1);
	  		cd=(c/d);
	  		int res2 = ef + cd;
	  		exit(res2);
	  	}
	  
	  }
	  else
	  {
	  	wait(&s2);
	  	int cdef = WEXITSTATUS(s2);
	  	ab= (a*b);
	    	int res3=cdef + ab ;
	    	exit(res3);
	  }
	}
	else
	{
		
		wait(&status);
		int final1= WEXITSTATUS(status);
		cout<<"\nA*B="<<ab;
		cout<<"\nC/D="<<cd;
		cout<<"\nE-F="<<ef;
		cout<<"\n(A*B) + (C/D) + (E-F)="<<final1;
	}
	
	
	
	return 0;
}
