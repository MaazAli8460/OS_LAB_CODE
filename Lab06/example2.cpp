#include<stdlib.h>
# include<unistd.h>
# include <string.h>
#include <stdio.h>
int main(){
int n;
int fd[2] ;
char buf[1025] ;
char const * data =" Hello this is written to pipe";
pipe(fd) ;
write (fd[1] , data , strlen( data )) ;
if((n=read(fd[0] , buf ,1024)) >= 0 ) {
    buf[n] = '\0' ;    
    printf( "Read %d bytes from pipe %s \n\n" , n , buf );
}
else{
    perror("Error");
    exit(0);
}
    return 0;

}
