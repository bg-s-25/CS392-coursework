/**
 * CS-392-B Process quiz
 * Bobby Georgiou | 03-29-2019
 * "I pledge my honor that I have abided by the Stevens Honor System."
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

/* Signal handler - terminate after 2nd SIGINT received */
static void hdl(int sig, siginfo_t *siginfo, void *context) {
    printf("[SIGINT received]\n");
}

int main() {
    // register handler
    struct sigaction act, old_act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &hdl;
    act.sa_flags = SA_SIGINFO | SA_RESETHAND; // SA_RESETHAND flag causes termination after 2nd SIGINT

    // sigaction(SIGINT, &act, &old_act);

    if (sigaction(SIGINT, &act, &old_act) < 0) {
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
