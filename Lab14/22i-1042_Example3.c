#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Using semaphore for IPC / Synchronization
sem_t sem;

void *f1(void *arg)
{
    printf("Child: begin\n");
    sem_post(&sem);
    printf("Child: end\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    sem_init(&sem, 0, 0);
    printf("parent: begin\n");
    pthread_create(&tid, NULL, f1, NULL);
    sem_wait(&sem);
    printf("parent: end\n");
    pthread_exit(NULL);
}