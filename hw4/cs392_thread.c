/**
    Title  : CS 392 B - HW Assignment 4
    Desc   : Multi-threaded program in which each thread reads/parses a file and syncs the results to global status variables
    Name   : Bobby Georgiou
    Date   : 04/21/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int item1_counter = 0;
int item2_counter = 0;
int item3_counter = 0;
pthread_mutex_t lock;

void * cs392_thread_run(void * arg) {
    // mutex lock
    pthread_mutex_lock(&lock);

    // open file and read lines
    arg = (char *)arg;
    FILE * fp = fopen(arg, "r");
    char buf[64];

    // modify counter values
    while (fgets(buf, 64, fp) != NULL) {
        int inc = buf[0] == '+';
        switch (buf[5]) {
            case '1':
                item1_counter += inc ? 1 : -1;
                break;
            case '2':
                item2_counter += inc ? 1 : -1;
                break;
            case '3':
                item3_counter += inc ? 1 : -1;
                break;
        }
    }

    fclose(fp);

    // mutex unlock
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("Usage: ./cs392_thread <file1> <file2> <file3>\n");
        exit(1);
    }
    
    for (int file_num = 1; file_num < 4; file_num++) {
        FILE * fp = fopen(argv[file_num], "r");
        if (fp == NULL) { // file not found
            perror("file");
            exit(1);
        }
        fclose(fp);
    }

    // initialize mutex to deal with race condition
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("mutex init");
        exit(1);
    }

    // create threads
    pthread_t tid1, tid2, tid3;
    int t_status;

    t_status = pthread_create(&tid1, NULL, cs392_thread_run, argv[1]);
    if (t_status != 0) {
        perror("thread1");
        exit(1);
    }

    t_status = pthread_create(&tid2, NULL, cs392_thread_run, argv[2]);
    if (t_status != 0) {
        perror("thread2");
        exit(1);
    }

    t_status = pthread_create(&tid3, NULL, cs392_thread_run, argv[3]);
    if (t_status != 0) {
        perror("thread3");
        exit(1);
    }

    // wait for threads to terminate
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    // destroy mutex lock
    pthread_mutex_destroy(&lock);

    // print final values
    printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d\n", item1_counter, item2_counter, item3_counter);

    return 0;
}
