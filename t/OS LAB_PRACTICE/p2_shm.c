#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of the shared memory segment

int main() {
    key_t key_shm = 1234;  // Key for the shared memory segment
    key_t key_sem = 5678;  // Key for the semaphore
    int shmid;
    int semid;
    char *shm_ptr;
    struct sembuf sb;

    // Get the shared memory segment
    if ((shmid = shmget(key_shm, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Get the semaphore
    if ((semid = semget(key_sem, 1, 0666)) < 0) {
        perror("semget");
        exit(1);
    }

    // Loop for bidirectional communication
    while (1) {
        // Wait for the semaphore
        sb.sem_num = 0;
        sb.sem_op = -1;
        sb.sem_flg = SEM_UNDO;
        if (semop(semid, &sb, 1) < 0) {
            perror("semop");
            exit(1);
        }

        // Read and print the message from shared memory
        printf("Program 2: Message from Program 1: %s\n", shm_ptr);

        // Release the semaphore
        sb.sem_op = 1;
        if (semop(semid, &sb, 1) < 0) {
            perror("semop");
            exit(1);
        }
    }

    // Detach from the shared memory segment
    shmdt(shm_ptr);

    return 0;
}
