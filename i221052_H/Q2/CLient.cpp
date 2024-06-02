#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(){

int choice[1];

cout << "Muhammad Aoun Jee		22i-1052		H" <<endl;
cout << "Client" <<endl;


int client = mkfifo ("MYFIFO" , 0666);

if(client < 0){
cout<< "ERROR" <<endl;
return 0;
}

client = open ( "MYFIFO" , O_WRONLY );

while(1){
cout << "WELCOME TO THE BANK..." << endl;
cout << "1. Check Balance" << endl;
cout << "2. Deposit Money" << endl;
cout << "3. Withdraw Money" << endl;
cout << "4. Exit" <<endl;
cout << "What would you like to do? "; cin >> choice[0];

if( choice[0] < 1 && choice[0] > 4)
cout << "Wrong Input" <<endl;
else 
write(client , choice , sizeof(choice));

}

close(client);



return 0;
}
