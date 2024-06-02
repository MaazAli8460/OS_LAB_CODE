#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
int main()
{
    sigset_t sigset;
    // f i l l sigset with a l l available OS signals 
    // sigaddset(&sigset, SIGINT);  
    // sigaddset(&sigset, SIGTSTP);  
    // sigaddset(&sigset, SIGQUIT); 
    sigfillset(& sigset) ;
    // sigprocmask(SIG_BLOCK , &sigset , NULL );
//Checking for membership / 
if (sigismember(& sigset , SIGINT ) ) 
    printf ( " SIGINT" ) ;
if (sigismember(&sigset, SIGQUIT))
    printf(" SIGQUIT");
if (sigismember(&sigset, SIGUSR1))
    printf(" SIGUSR1");
if (sigismember(&sigset, SIGALRM))
    printf(" SIGALRM\n");
//Deleting SIGUSR1 from sigset / 
sigdelset(&sigset, SIGUSR1);
if (sigismember(&sigset,
                SIGUSR1))
    printf("SIGUSR1\n");
else printf ( "SIGUSR1 is Now not member of Empty the sigset");
sigemptyset(& sigset ) ;
if ( sigismember(& sigset , SIGALRM) ) printf ( " SIGALRM"
) ;
else printf ( " Sigset is empty\n sigset \n" ) ;
return 0;
}