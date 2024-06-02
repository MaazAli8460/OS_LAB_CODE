#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    signal(SIGQUIT, SIG_DFL); // Reset the signal handler for SIGQUIT
}

void sig_term(int signo)
{
    printf("caught SIGINT\n");
    signal(SIGINT, SIG_DFL); // Reset the signal handler for SIGINT
}

int main(void)
{
    sigset_t newmask, oldmask, pendmask;

    // Register signal handlers for SIGQUIT and SIGINT
    signal(SIGQUIT, sig_quit);
    signal(SIGINT, sig_term);

    // Block SIGQUIT and SIGINT and save current signal mask
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    sigaddset(&newmask, SIGINT);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    printf("Sleep for 10 seconds\n");
    sleep(10);

    // Check if SIGQUIT and SIGINT are pending
    sigpending(&pendmask);
    if (sigismember(&pendmask, SIGQUIT) && sigismember(&pendmask, SIGINT))
    {
        printf("\nSIGQUIT && SIGINT are pending\n");
    }

    // Restore signal mask to unblock SIGQUIT and SIGINT
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    printf("SIGQUIT && SIGINT unblocked\n");

    while (1)
    {
    }

    exit(0);
}