/* Shared memory practice - structs */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // create shared memory region
    key_t const KEY = ftok("./", 1);
    int shm_id = shmget(KEY, 2 * sizeof(int), IPC_CREAT | 0666);

    // attach shared memory
    struct shared_data { int a; int b; };
    struct shared_data * p;
    p = (struct shared_data *) shmat(shm_id, NULL, 0);
    // if ((int) p < 0) {
    //     printf("shmat failed\n");
    //     exit(1);
    // }

    // change value of first integer
    p->a = 1;

    // wait for value of b to change
    while (p->b != 1) {

    }

    printf("Integer b changed to 1!\n");

    // detach shared memory
    shmdt((void *) p);

    // delete shared memory
    shmctl(shm_id, IPC_RMID, NULL);

    exit(0);
}