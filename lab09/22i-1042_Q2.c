#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//#include <cstring>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>


struct thr
{
    FILE * fp;
    int thread_id;
};

void *func1_create_file(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    data->fp = fopen("Lab09.txt", "w+");
    if (!data->fp)
    {
        data->fp = fopen("Lab09.txt", "r+");
        if (data->fp == NULL)
        {
            printf("Error creating file Lab09.txt\n");
    pthread_exit(NULL);
            
        }
    }
    fprintf(data->fp,"THIS IS WRITTEN TO FILE FROM THREAD 1");
    fclose(data->fp);
    pthread_exit(NULL);
}
void *func2_write_to_file(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    data->fp=fopen("Lab09.txt","a+");
    char buffer[256];
    char input;
    while((input = getchar()) != 27)
    {
        fputc(input,data->fp);
    }
    
    pthread_exit(NULL);

}
int main()
{
  pthread_t thr1, thr2;
  struct thr d1 = {NULL,0};
  struct thr d2 = {NULL,1};
  pthread_create(&thr1, NULL, func1_create_file, &d1);
  pthread_create(&thr2, NULL, func2_write_to_file, &d2);

  // Wait for both threads to finish
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  // Print a message to indicate that the program has finished
  printf("The program has finished writing to the file.\n");
    return 0;
}