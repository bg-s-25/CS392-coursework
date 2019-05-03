#include <stdio.h>
#include <signal.h>
#include <unistd.h> // only works on UNIX systems

// Changes signal handler from default (TERMINATE) to code in this method
void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("received SIGINT\n");
    }
}

int main(void) {
    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        printf("\nCan't catch SIGNINT\n");
    }
    while (1) {
        sleep(1);
    }
    return 0;
}
