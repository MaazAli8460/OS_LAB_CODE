#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_t thread1, thread2;
int counter = 0;

void *functionC(void *p) {
    pthread_mutex_lock(&mutex1);
    counter++;
    printf("Thread %ld Counter value : %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(&thread1, NULL, &functionC, NULL);
    pthread_create(&thread2, NULL, &functionC, NULL);
    printf("Thread 1 ID : %ld \n", thread1);
    printf("Thread 2 ID : %ld \n", thread2);
    sleep(3);
    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex1);
    pthread_exit(NULL);
    exit(0);
}