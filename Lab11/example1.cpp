#include<iostream>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

using namespace std;

int main()
{
    pid_t pid=fork();
    if (pid<0)
    {
        cout<<"\nChild not  created\n";
        /* code */
    }
    else if(pid>0)
    {
        cout<<"\nI am parent with pid"<<getpid()<<" And  My child has pid "<<pid<<endl;
        wait(NULL);
    }
    else
    {
        cout<<"\nIm child with pid:"<<getpid()<<" My parent is:"<<getppid()<<endl;
        kill(getppid(),SIGKILL);
        cout<<"My parent now is:"<<getppid()<<endl;
        sleep(1);
        cout<<"My parent now is:"<<getppid()<<endl;

    }
    return 0;
}