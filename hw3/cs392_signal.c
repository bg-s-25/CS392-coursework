/**
    Title  : CS 392 B - HW Assignment 3
    Desc   : Register handler for SIGINT and SIGTSTP signals
    Name   : Bobby Georgiou
    Date   : 04/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "cs392_signal.h"

/**
 * Signal handler
 */
static void handler(int sig, siginfo_t *siginfo, void *context) {
    if (sig == SIGINT) {
        printf("\n[SIGINT received]\n");
    } else if (sig == SIGTSTP) {
        printf("\n[SIGTSTP received]\n");
    }
}

/**
 * Register handlers for SIGINT and SIGTSTP
 */
void register_handlers() {
    // register handler
    struct sigaction act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        exit(1);
    }

    if (sigaction(SIGTSTP, &act, NULL) < 0) {
        perror("sigaction");
        exit(1);
    }
}
