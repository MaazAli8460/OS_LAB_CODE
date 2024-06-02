#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int pipe1 = open("calculator1", O_WRONLY | O_CREAT, 0666);
    if (pipe1 < 0) {
        cout << "ERROR: Pipe could not be created!" << endl;
        return 1;
    }

    int num1, num2;
    int choice = 0;
    int buffer[2]; // Buffer size to hold two integers
    while (choice != 5) {
        cout << "\nEnter num 1:";
        cin >> num1;

        cout << "\nEnter num 2:";
        cin >> num2;

        cout << "\nEnter your choice:";
        cin >> choice;

        buffer[0] = num1;
        buffer[1] = num2;

        write(pipe1, buffer, sizeof(buffer));

        int p_id = fork();
        if (p_id == 0) {
            execl("./addproc", "./addproc", "calculator1", NULL);
            cout << "ERROR: exec failed!" << endl;
            exit(1);
        } else {
            wait(NULL);
int result_pipe = open("calculator1", O_RDONLY);
char var;
read(result_pipe, &var, sizeof(var));
close(result_pipe);

// Print the integer value directly
cout << "\ncalculation from child: " << static_cast<int>(var) << endl;
        }
    }

    close(pipe1);
    return 0;
}
