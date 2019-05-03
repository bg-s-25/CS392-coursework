/**
 * CS 392: Thread practice
 * New threads are not child processes; 
 * new threads are located in the same address space, but have a different stack and heap than the master thread
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Static methods cannot be used by any other source file
static void * run_thread() {
    printf("Printing from new thread.\n");
    return NULL; // exit thread (can also use pthread_exit(NULL))
}

int main() {
    // create thread
    pthread_t tid;
    int threads, e, i;

    e = pthread_create(&tid, NULL, run_thread, NULL);
    if (e != 0) {
        perror("thread");
        exit(1);
    }

    pthread_join(tid, NULL);

    return 0;
}