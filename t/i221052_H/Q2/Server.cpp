#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(){
int server[1];
int client;

int balance = 10000;

cout << "Muhammad Aoun Jee		22i-1052		H" <<endl;

client = open("MYFIFO" , O_RDONLY);

read( client , server , sizeof(server));

cout << server[0] <<endl;

if(server[0] == 1){
cout << "Current balance : " << balance << endl;
}

else if ( server[0] == 2){
int money;
cout << "Enter Amount you would like to deposit";cin >> money;
balance += money;

cout << "Balance after Deposti : " << balance <<endl;

}
else if(server[0] == 3){
int money;
cout << "Enter Amount you would like to withdraw : "; cin >> money;
if ((balance - money) < 0) cout << "Insufficient Balance." <<endl;
else
balance -= money; 

cout << "Balance after Withdraw : " << balance <<endl;
}

else if(server[3] == 4)
return 0;

else
cout << "Incorrect Input." <<endl;




return 0;
}
