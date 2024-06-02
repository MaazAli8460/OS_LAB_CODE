#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int i;
    void* shared_memory;
    char buff[100];
    int shmid;

    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT); 
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    printf("Key of the shared memory is: %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("Process attached at: %p\n", shared_memory);
    printf("WRITE SOMETHING INTO SHARED MEMORY: ");
    fgets(buff, 100, stdin); 
    strcpy((char*)shared_memory, buff);

    printf("Data read from shared memory is: %s\n", (char*)shared_memory);

    if (shmdt(shared_memory) == -1) { 
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}
