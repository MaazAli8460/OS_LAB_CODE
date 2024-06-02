#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#include<sys/wait.h>
#include<signal.h>

using namespace std;
void handler(int signum)
{
    cout<<"\nSignal is receved:"<<signum<<endl;
    sleep(5);
    wait(NULL);
}
int main()
{
    int cpid,ppid;
    signal(SIGUSR1,handler);
    signal(SIGCHLD,handler);
    cpid=fork();
    switch(cpid)
    {
        case -1:
        cout<<"\nERROR"<<endl;
        break;

        case 0:
        ppid=getppid();
        kill(ppid,SIGUSR1); //
        exit(0);
        break;

        default:
        while (kill(cpid,0)==0)
        {
            cout<<"\nWaiting for child\n";

        }
        cout<<"\nChild terminated so ending.\n";
        exit (0);
        break;
    }
    
    return 0;
}