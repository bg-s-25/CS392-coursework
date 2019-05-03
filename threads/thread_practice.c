/**
 * CS 392: Thread in-class practice
 * New threads are not child processes; 
 * new threads are located in the same address space, but have a different stack and heap than the master thread
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

static void * run_thread() {
    int i = 0;
    for (i = 0; i < 1000; i++) {
        counter++;
    }
    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    // create thread
    int t_stat; // thread status indicator
    t_stat = pthread_create(&tid1, NULL, run_thread, NULL);
    if (t_stat != 0) {
        perror("thread1");
        exit(1);
    }

    t_stat = pthread_create(&tid2, NULL, run_thread, NULL);
    if (t_stat != 0) {
        perror("thread2");
        exit(1);
    }

    // wait for threads to terminate
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // both threads increment counter by 1000, making the final value 2000
    printf("%d\n", counter);

    return 0;
}