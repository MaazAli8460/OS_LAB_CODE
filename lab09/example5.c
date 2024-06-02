#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_data {
    pthread_t *thread_id;
    char *message;
};

struct thread_data thread_data;

void *thr_fn(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    pthread_t *taskid = my_data->thread_id;
    char *hello_msg = my_data->message;
    printf("Thread id is : %ld \nMessage : %s \n", *taskid, hello_msg);
    pthread_exit((void *) " Successful");
}

int main(int argc, char *argv[]) {
    pthread_t thread_id;
    thread_data.message = " Have you learnt something today?\n";
    thread_data.thread_id = &thread_id;
    printf("Creating thread\n");
    pthread_create(&thread_id, NULL, thr_fn, (void *)&thread_data);
    void *status;
    pthread_join(thread_id, &status);
    printf("Thread Exited with status : %s\n", (char *) status);
    exit(0);
}