#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>

int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int arr2[3][3] = {{11, 22, 33}, {44, 55, 66}, {77, 88, 99}};
int res[3][3];

void *Row(void *arg)
{
    int oldstate, var;
    var = (int)arg;
    int *arr = malloc(3 * sizeof(int));
    printf("\nVar=%d\n", var);
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
    for (int i = 0; i < 3; i++)
    {
        arr[i] = 0; 
        for (int j = 0; j < 3; j++)
        {
            arr[i] += arr1[var][j] * arr2[j][i]; 
        }
    }
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    pthread_exit(arr);
}

int main()
{
    pthread_t thread[3];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&thread[i], &attr, Row, (void *)i);
    }

    pthread_attr_destroy(&attr);
    void *stat;
    for (int i = 0; i < 3; i++)
    {
        pthread_join(thread[i], &stat);
        int *arr = (int *)stat;
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = arr[j]; 
        }
        free(arr); 
    }
    printf("\nResultant_matrix:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", res[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL);

    return 0;
}