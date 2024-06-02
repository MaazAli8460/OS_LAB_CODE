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
    char buffer[2];
	pipe1 = open("comunicator1", O_RDONLY);
    read(pipe1, buffer, sizeof(buffer));
	cout<<"\nSum:"<<buffer[0]<<"+"<<buffer[1]<<"="<<static_cast<int>(buffer[0])+static_cast<int>(buffer[1])<<endl;
	close(pipe1);
	return 0;
}
