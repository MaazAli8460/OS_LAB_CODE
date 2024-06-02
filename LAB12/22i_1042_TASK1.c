#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>

int arr[3][3];
int col_sum[3];
int row_sum[3];
char output[256];

void *thread_function1(void *arg)
{
    int oldstate;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fprintf(file, "%d ", arr[i][j]);
            fprintf(file, "%c ", ' ');
        }
        fprintf(file, "\n");
    }

    fclose(file);
    
    pthread_exit(0);
}
void *thread_function2(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

    // Read matrix from file
    printf("Processing matrix...\n");
    FILE *file = fopen("matrix.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(file, "%d", &arr[i][j]);
            row_sum[i] += arr[i][j];
            col_sum[j] += arr[i][j];
        }
    }

    fclose(file);

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (row_sum[i] == col_sum[j]) {
                sprintf(output + strlen(output), "Row %d and Column %d have equal sums.\n", i + 1, j + 1);
            }
        }
    }

    
    file = fopen("result.txt", "w");
    if (file == NULL) {
        perror("Error opening result.txt file");
        pthread_exit(NULL);
    }

    fprintf(file, "%s", output);
    fclose(file);
    printf("Result processed and stored in result.txt\n");

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    return NULL;
}
void *thread_function3(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

   
    printf("Displaying result...\n");
    FILE *file = fopen("result.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    return NULL;
}

int main()
{

    pthread_t tid1;

    pthread_t thread[3];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_create(&thread[0], &attr, thread_function1, NULL);
    pthread_create(&thread[1], &attr, thread_function2, NULL);
    pthread_create(&thread[2], &attr, thread_function3, NULL);

    pthread_attr_destroy(&attr);

    for (int i = 0; i < 3; i++) {
        pthread_join(thread[i], NULL);
    }
    pthread_exit(NULL);
    return 0;
}