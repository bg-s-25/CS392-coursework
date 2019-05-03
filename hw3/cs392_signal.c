/**
    Title  : CS 392 B - HW Assignment 3
    Desc   : Handle SIGINT and SIGSTOP signals
    Name   : Bobby Georgiou
    Date   : 04/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h> // needed?

/**
 * Signal handler
 */
static void hdl(int sig, siginfo_t *siginfo, void *context) {
    if (sig == SIGINT) {
        printf("[SIGINT received]\n");
    } else if (sig == SIGSTOP) {
        printf("[SIGSTOP received]\n");
    }
}

int main() {
    // register handler
    struct sigaction act, old_act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &hdl;
    act.sa_flags = SA_SIGINFO | SA_RESETHAND; // SA_RESETHAND flag causes termination after 2nd signal

    // sigaction(SIGINT, &act, &old_act);

    if (sigaction(SIGINT, &act, &old_act) < 0) {
        perror("sigaction");
        return 1;
    }
    if (sigaction(SIGSTOP, &act, &old_act) < 0) {
        perror("sigaction");
        return 1;
    }

    // loop
    while (1) {
        sleep(1);
        printf("Hellow\n");
    }
    return 0;
}
