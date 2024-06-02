#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
using namespace std;

int main() {
    char str[256] = {0}; 
    int fifo_write;
  int f1, f2;
    

    f1 = mkfifo("pipe_one", 0666);

    fifo_write = open("pipe_one", O_WRONLY);


    if (fifo_write < 0) {
        cout << "Error opening file";
    } else {
        while (strcmp(str, "abort") != 0) {
            cout << "Enter text: ";
            cin.getline(str, sizeof(str)); // Read input line
            write(fifo_write, str, strlen(str)); 
            cout << "* " << str << " *" << endl;
        }
        close(fifo_write);
    }
    return 0;
}

