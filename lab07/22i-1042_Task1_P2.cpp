#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int main()
{
	
    int pipe1;
    char buffer[100];
    while(1){


	pipe1 = open("comunicator1", O_RDONLY);
        read(pipe1, buffer, sizeof(buffer));
	cout<<"\nProcess1:"<<buffer<<endl;
	close(pipe1);
	
	
        cout<<"\n : ";
        cin.getline(buffer, sizeof(buffer)); 
        pipe1 = open("comunicator1", O_WRONLY);

        //write(pipe1, &ave, sizeof(ave));
        write(pipe1, buffer, sizeof(buffer));
        close(pipe1);
    }
	return 0;
}
