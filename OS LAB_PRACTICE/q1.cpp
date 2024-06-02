# include<iostream>
# include<cstdlib> 
#include<unistd.h>
using namespace std ; 
int main () {
char buffer [10] ;
cout <<"Enter s t r i n g :"<<endl ;
read ( 0 , buffer , 10 ) ;
write ( 1 , buffer , 10 ) ;
write ( 2 , buffer , 10 ) ;
return 0 ;
}
