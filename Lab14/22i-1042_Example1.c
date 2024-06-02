#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Using semaphore as a Binary lock for IPC / Synchronization
sem_t sem;

void *f1(void *arg) {
    sem_wait(&sem);
    printf("Thread with ID:%ld got lock\n", pthread_self());
    sleep(2);
    sem_post(&sem);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;
    sem_init(&sem, 0, 1);
    pthread_create(&tid1, NULL, f1, NULL);
    pthread_create(&tid2, NULL, f1, NULL);
    pthread_exit(NULL);
}