
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>
/*
int main () {
pid_t pid= fork( ) ;
if( pid == 0 )
printf( " I am Child process \n" ) ;
else if ( pid > 0 )
printf( " I am Parent process \n" ) ;
else if( pid < 0 )
printf( " Error in Fork " ) ;
return 0;
}



int main() {
pid_t pid= fork( ) ;
int status=0;
pid_t wait(int* status);
if( pid == 0 ) {
printf( " I am Child process with pid %d and i am not waiting\n" , getpid ( ) ) ;
exit(status ) ;
}
else if( pid > 0 ) {
printf( " I am Parent process with pid %d andi am waiting\n" , getpid ( ) ) ;
pid_t exitedChildId=wait(&status ) ;
printf( " I am Parent process and the child with pid %d is exited \n" , exitedChildId ) ;
}
else if( pid < 0 ) {
printf( " Error in Fork " ) ;
}
return 0;
}

#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
*/
int global =0;
int main()
{
int status;
pid_t child_pid;
int local;
child_pid=fork();
if( child_pid >= 0 ) {
if( child_pid == 0 ) {
printf( " child process !\n" ) ;
local++;
global++;
printf( " child PID = %d , parent pid = %d\n" , getpid ( ) , getppid ( ) ) ;
printf( "\n child’s local = %d , child’s global = %d\n" , local , global ) ;
}
else{
printf( " parent process !\n" ) ;
printf( " parent PID = %d , child pid = %d\n" ,getpid ( ) , child_pid ) ;
int w=wait(&status ) ;
printf( "\n Parent’s local = %d , parent’s global= %d\n" , local , global ) ;
printf( " Parent says bye !\n" ) ;
}
exit(0);
}
else
{
perror( " fork " ) ;
exit(0) ;
}
return 0;
}

