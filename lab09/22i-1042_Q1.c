#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_id_1, thread_id_2;

void *thr_fn_1(void *thread_id) {
    sleep(1);
    printf("Thread 1 : #%ld ! and I am printing even less than 20\n", pthread_self());
    int i = 0;
    for (i; i < 20; i++) {
        if (i%2==0)
        {
            printf("%d,",i);
        }
    }
    pthread_exit(NULL);
}

void *thr_fn_2(void *thread_id) {
    printf("Thread 2 : #%ld ! and I am printing odd less than 20\n", pthread_self());
    int i = 0;
    for (i; i < 20; i++) {
        if (i%2!=0)
        {
            printf("%d,",i);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    printf("main : creating thread\n");
    pthread_create(&thread_id_1, NULL, thr_fn_1, NULL);
    pthread_create(&thread_id_2, NULL, thr_fn_2, NULL);
    pthread_join(thread_id_2, NULL);
    printf("main : Both threads exited\n");
    pthread_exit(NULL);
}