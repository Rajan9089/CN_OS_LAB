#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>

#define SIZE 10

int *integer = 0;

int accessmem(int semid); // Function prototype

int main() {
    int shmid;
    key_t key_10;
    char *shm;
    int semid, pid;

    // Create shared memory segment
    shmid = shmget((key_t)key_10, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        return 1;
    }

    integer = (int *)shm;

    // Create semaphore
    semid = semget((key_t)1234, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    // Initialize semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        int i = 0;
        while (i < 10) {
            sleep(3);
            printf("\nchild process used shared memory");
            accessmem(semid);
            i++;
        }
    } else {
        int j = 0;
        while (j < 10) {
            sleep(2);
            printf("\nParent process uses shared memory");
            accessmem(semid);
            j++;
        }
    }

    // Detach shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    // Remove semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID");
        return 1;
    }

    return 0;
}

int accessmem(int semid) {
    struct sembuf sop;
    sop.sem_num = 0;
    sop.sem_op = -1; // Wait for the semaphore
    sop.sem_flg = 0;
    semop(semid, &sop, 1);

    (*integer)++;

    sop.sem_op = 1; // Release the semaphore
    semop(semid, &sop, 1);

    return 0;
}

