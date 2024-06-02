#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct student_database {
    int roll_no;
    float cgpa;
};

struct student_database obj;

void * print_fn(void * threadarg) {
    struct student_database * temp_data;
    temp_data = (struct student_database *) threadarg;
    int rollno = temp_data->roll_no;
    float cgpa = temp_data->cgpa;
    printf(" Inside Thread\n");
    printf(" Roll no %d has cgpa :%f\n", rollno, cgpa);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    pthread_t thread_id;
    obj.roll_no = 90010;
    obj.cgpa = 3.88;
    printf(" Creating thread\n");
    pthread_create(&thread_id, NULL, print_fn, &obj);
    pthread_exit(NULL);
}