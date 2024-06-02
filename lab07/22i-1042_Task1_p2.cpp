#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring> 
#include <cstdlib>
using namespace std;

int main()
{
    int pipe1 = mkfifo("comunicator1", 0666);
    
    if(pipe1 < 0){
        cout << "ERROR: Pipe could not be created!" << endl;
        return 0;
    }

   
    char buffer[100];
    while(1){

        cout << "\n : ";
        cin.getline(buffer, sizeof(buffer)); 
        //cin>>buffer;
        pipe1 = open("comunicator1", O_WRONLY);

        //write(pipe1, &ave, sizeof(ave));
        write(pipe1, buffer, strlen(buffer) + 1);
        close(pipe1);

        
        pipe1 = open("comunicator1", O_RDONLY);
        read(pipe1, buffer, sizeof(buffer));
        cout << "\nProcess2: " << buffer << endl;
        
        close(pipe1);

    }

    unlink("comunicator1");
    return 0;
}
