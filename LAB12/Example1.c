#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

void * thread_function (void * arg) {
  sleep (2);
  printf("thread_function is running. Argument was\" %s\"\n", (char *) arg);
  printf("thread 1 awaked from sleep and exiting now\n");
  pthread_exit (NULL);
}

int main () {
  char message [] = "iam thread 1";
  pthread_t tid;

  pthread_create (&tid, NULL, thread_function, (void*) message);

  // In 2nd run make following statement comment then
  //pthread_detach (tid);
  
  int joinret=pthread_join(tid, NULL);

  if (joinret == 0) 
      printf("join was successfull: The main thread was waiting for thread 1\n");
  else 
      printf("Join failed: The main thread is not waiting for thread 1\n");

  printf("The main thread finished, bye!\n");
  pthread_exit (NULL);
}
