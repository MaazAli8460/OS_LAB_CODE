#include<iostream>
#include<stdlib.h>
#include<unistd.h>

#include<sys/wait.h>
#include<signal.h>

using namespace std;


int main()
{
    
    cout<<"\nSucidal program\n";
    raise(SIGKILL);

    cout<<"\nTerminating.....\n";
    
    return 0;
}