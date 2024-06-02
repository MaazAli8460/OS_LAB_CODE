#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <string.h>

using namespace std;

int main() {
    int fd[2];
    pid_t childpid;
    char string[] = "Hello world\n";
    char readbuffer[80];
    int result = pipe(fd);
    if (result < 0) {
        cout << "Error while creating pipe\n";
        exit(1);
    }
    childpid = fork();
    if (childpid == -1) {
        cout << "Error in fork" << endl;
        exit(1);
    }
    if (childpid == 0) {
        close(fd[0]);
        cout << "Child writing to the pipe" << endl;
        write(fd[1], string, sizeof(string));
        cout << "Written to a file" << endl;
        exit(0);
    } else {
        close(fd[1]);
        wait(NULL);
        cout << "Parent reading from the pipe" << endl;
        read(fd[0], readbuffer, sizeof(readbuffer));
        cout << "Received string: " << readbuffer << endl;
        exit(0);
    }
    return 0;
}
