#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <cstring>
using namespace std;

int max_player=10;
struct SharedDataStruct {
    int group_amount;
    int guesses[10];
    int playerAmmount[10];
    int pipes[10][2];
    int bet_amounts[10];
};

int main(int argc,char* argv[]) 
{
    int shmid = shmget((key_t)1234, sizeof(SharedDataStruct), IPC_CREAT | 0666);
    SharedDataStruct *shared_data = (SharedDataStruct *)shmat(shmid, NULL, 0);
    cout<<"Player "<<argv[0]<<", Enter your base ammount:";
    int index=stoi(argv[0]);
    cin>>shared_data->playerAmmount[index-1];
    
    write(shared_data->pipes[index-1][1], &shared_data->playerAmmount[index-1], sizeof(int));
    
    char q='l';
    while(shared_data->playerAmmount[index-1]>0 && q!='q')
    {
    	cout<<"\nEnter your bet:";
    	cin>>shared_data->bet_amounts[index-1];
    	cout<<"\nEnter your choice of number from (1 - 10):";
    	cin>>shared_data->guesses[index-1];
    	write(shared_data->pipes[index-1][1], &shared_data->guesses[index-1], sizeof(int));
    	cout<<"\n Press 'q' t quit. to continue press any key.\n";
    	cin>>q;
    
    }

    return 0;
}

