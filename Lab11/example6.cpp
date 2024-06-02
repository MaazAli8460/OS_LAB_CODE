#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    // Define a new signal mask set to store different signals
    sigset_t new_mask;
    // Initialize and empty the new_mask set
    sigemptyset(&new_mask);

    // Adding SIGQUIT to the set named as new_mask
    sigaddset(&new_mask, SIGQUIT);
    // Adding SIGTSTP to the set named as new_mask
    sigaddset(&new_mask, SIGTSTP);
    // Adding SIGINT to the set named as new_mask
    sigaddset(&new_mask, SIGINT);

    // Block all the signals present in the new_mask set
    sigprocmask(SIG_BLOCK, &new_mask, NULL);

    int i = 0;
    for (i;; i++)
    {
        printf("\n%d\n", i);
        printf("My PID is %d\n", getpid());
        printf("You can't close me using conventional commands\n");
        sleep(2);
    }
    return 0;
}
