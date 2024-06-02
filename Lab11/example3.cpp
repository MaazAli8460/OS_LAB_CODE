#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#include<sys/wait.h>
#include<signal.h>

using namespace std;

void handler(int signum)
{
    cout<<"\nSignal is receved:"<<signum<<endl;
    
}
int main()
{
    int cpid,ppid;
    signal(SIGINT,handler);

    cout<<"\nBegin Execution press ctrl + c to continue\n";
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout<<"\nValue of i="<<i;
        cout<<endl;
        pause();
    }
    
    
    return 0;
}