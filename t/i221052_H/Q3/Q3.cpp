#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

bool isPrime(int num){

int check = 0;
for(int i = 1 ; i < num ; i++){

if(num % i == 0)
check+=1;

}

if (check = 2)
return true;
else 
return false;

}


int factorial(int num){
	if(num == 1 || num == 0)
	return 1;
	
	if(num < 0) return 0;
	
	else
	 return num * factorial(num-1);
}

bool isPerfectSquare(int num){
	bool check = false;
	for(int i = 0 ; i < num/2 ; i++){
	if(i*i == num)
	check = true;
	}
	
return check;	
	
}

using namespace std;

int main (){

cout << "Muhammad Aoun Jee		H		22i-1052" <<endl;

int choice;

cout << "What would you like to do?" <<endl;
cout << "1. Check if its Prime." <<endl;
cout << "2. Calculate its Fatorial." <<endl;
cout << "3. Check whether number is a perfect square." <<endl;
cout << "Enter Number : "; int num ; cin >> num;
cout << "Enter Choice : "; cin >> choice;

if(choice == 1){
 if(isPrime(num))
	cout << "It is Prime." << endl;
 else
	cout << "It is not Prime." <<endl; 
}

else if(choice == 2){
	cout << "Factroial : " << factorial(num) << endl;
}

else if(choice == 3){
	if(isPerfectSquare(num)){
	cout << "Number is Perfect Square." <<endl;
	}
	else
	cout << "Number is not Perfect Square." <<endl;
}
else
	cout << "Wrong Input" <<endl;

return 0;
}
