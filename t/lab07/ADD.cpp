#include <unistd.h>
#include <iostream>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <pipe_name>" << endl;
        exit(1);
    }

    int pipe1;
    char buffer[2]; // Buffer size to hold two integers
    pipe1 = open(argv[1], O_RDONLY);
    read(pipe1, buffer, sizeof(buffer));
    close(pipe1);

    int num1 = static_cast<int>(buffer[0])-'0';  // Convert char to int
    int num2 = static_cast<int>(buffer[1])-'0';  // Convert char to int

    int sum = num1 + num2;

    pipe1 = open(argv[1], O_WRONLY);
    write(pipe1, &sum, sizeof(sum));
    close(pipe1);

    return 0;
}
