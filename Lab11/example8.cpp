
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_suspend(int signo)
{
    printf("\nIn sig_suspend handler with signal number: %d\n", signo);
}

void sig_int(int signo)
{
    printf("\nIn sig_int handler:\n");
}

int main()
{
    sigset_t newmask, oldmask, waitmask;

    printf("Program start with PID: %d\n", getpid());

    // Registering signal handlers
    signal(SIGINT, sig_int);
    signal(SIGALRM, sig_suspend);
    signal(SIGUSR1, sig_suspend);

    // Initializing waitmask set
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigaddset(&waitmask, SIGALRM);

    // Blocking SIGINT and saving current signal mask
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    // Critical region of code
    printf("In the critical region:\n");
    printf("It will pause until received any signal except SIGUSR1 & SIGALRM.\n");
    // Suspends the process until a signal is caught
    sigsuspend(&waitmask);
    // Now onwards old mask "newmask" is applicable
    printf("After returning from sigsuspend:\n");
    sleep(15);

    // Unblocking newmask set
    sigprocmask(SIG_UNBLOCK, &newmask, NULL);

    // Continuing processing
    printf("Program end.\n");

    exit(0);
}