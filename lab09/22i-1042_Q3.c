#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>


struct thr
{
    int num1;
    int num2;
};

void *MUL(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    int res= data->num1 * data->num2;
    return ((void*)res);
}
void *DIV(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    int res= data->num1 / data->num2;
    return ((void*)res);
}
void *ADD(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    int res= data->num1 + data->num2;
    return ((void*)res);
}
void *SUB(void* thr1)
{
    struct thr *data = (struct thr *) thr1;
    int res= data->num1 - data->num2;
    return ((void*)res);
}

int main()
{
  pthread_t thr1, thr2,thr3,thr4;
  int num1,num2;
  printf( "Enter the first number: ");
  scanf("%d", &num1 );
  printf( "Enter the second number: ");
  scanf("%d", &num2 );
  struct thr d1 = {num1,num2};
    int choice;
    printf("Menu:\n1 for ADD.\n2. for SUB.\n3.  for Div\n4. for MUL\n choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1 /* constant-expression */:
        /* code */
        pthread_create(&thr1, NULL, ADD, &d1);
        break;
    case 2 /* constant-expression */:
        /* code */
          pthread_create(&thr1, NULL, SUB, &d1);

        break;
    case 3 /* constant-expression */:
        /* code */
  pthread_create(&thr1, NULL, MUL, &d1);

        break;
    case 4 /* constant-expression */:
        /* code */
  pthread_create(&thr1, NULL, DIV, &d1);

        break;
    
    default:
        break;
    }
  // Wait for both threads to finish
  int result;
  pthread_join(thr1, (void**)&result);
 printf("RESULT= %d \n" ,result);

  // Print a message to indicate that the program has finished
  printf("The program has finished writing to the file.\n");
    return 0;
}