#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <time.h>
#include<cstring>

using namespace std;
int max_player=10;
struct SharedDataStruct {
    int group_amount=0;
    int guesses[10];
    int playerAmmount[10];
    int pipes[10][2];
    int bet_amounts[10];
};
int main()
{
    pid_t childpid;
    int i;
    int shmid = shmget((key_t)1234, sizeof(SharedDataStruct), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    SharedDataStruct *shared_memory = (SharedDataStruct *)shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    
    shared_memory->group_amount = 0;
    cout<<"\nEnter number 1 - 10:"<<endl;
	cout<<"\nEnter number of players:";
	int am;
	cin>>am;
	
	for (int i = 0; i < am; i++) {
        if (pipe(shared_memory->pipes[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

	for(int i=0;i<am;i++)
	{
		childpid=fork();
		if (childpid < 0) {
            perror("fork");
            exit(1);
        } else if (childpid == 0) { 
            close(shared_memory->pipes[i][0]); 
            
            execl("./child1",(const char*)i, NULL); 
            perror("execl"); 
            exit(1);
        }
	}
	close(shared_memory->pipes[0][1]); 
	
	while(true)
	{
		
        for (int i = 0; i < am; i++) {
        void* var;
            read(shared_memory->pipes[i][0], var, sizeof(int));
            shared_memory->group_amount+=*(int*)var;
            
        }
        int randnum=rand()%9 +1;
        for (int i = 0; i < am; i++) {
        	if(shared_memory->bet_amounts[i]==randnum)
        	{
        		cout<<"\nplayer "<<i+1<<" won 10 x betting ammount\n";
        		int temp= shared_memory->bet_amounts[i] *10;
        		shared_memory->group_amount+=temp;
        	}
        	else
        	{
        		shared_memory->group_amount-shared_memory->bet_amounts[i];
        	}
        }

        printf("Group amount: %d\n", shared_memory->group_amount);
    
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);

    
    for (int i = 0; i < am; i++) {
        close(shared_memory->pipes[i][0]);
        close(shared_memory->pipes[i][1]);
    }

    
    for (int i = 0; i < am; i++) {
        wait(NULL);
    }
    }

    

return 0;
}
