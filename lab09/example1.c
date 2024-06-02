#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* This function is run by the second thread */
void *inc_x(void *arg) {
    printf("Thread: Process Id is %d and Thread Id is %ld\n", getpid(), pthread_self());

    int *input;
    input = (int *)arg;
    while (++(*input) < 100);
    printf("x increment finished\n");

    /* The function must return something - NULL will do */
    pthread_exit(NULL);
}

int main() { // main Thread
    int x = 0, y = 0;
    /* show the initial values of x and y */
    printf("x: %d, y: %d\n", x, y);
    printf("main: Process Id is %d and Thread Id is %ld\n", getpid(), pthread_self());

    /* this variable is our reference to the second thread */
    pthread_t thread_2;
    /* create a second thread */
    pthread_create(&thread_2, NULL, inc_x, &x);
    /* increment y to 100 in the first thread */
    while (++y < 100);
    /* wait for the second thread to finish */
    pthread_join(thread_2, NULL);

    /* show the results - x is now 100 */
    printf("x: %d, y: %d\n", x, y);

    pthread_exit(NULL);
}
