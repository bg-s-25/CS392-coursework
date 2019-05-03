/**
 * CS 392 B - Daemon Process Quiz
 * Bobby Georgiou
 * 04/26/2019
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void) {
    // fork
    pid_t pid = fork();
    if (pid < 0) { // fork failure
        exit(1);
    } else if (pid > 0) { // exit parent
        exit(0);
    }

    // change file mode mask
    umask(0);

    // create new SID
    pid_t sid = setsid();
    if (sid < 0) {
        perror("sid");
        exit(1);
    }

    // change working directory to /tmp/ in root dir
    if ((chdir("/tmp")) < 0) {
        perror("chdir");
        exit(1);
    }

    // close file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // open file
    FILE * fp = fopen("cs392_daemon.log", "a");
    if (fp == NULL) {
        perror("file");
        exit(1);
    }

    // get time & append to file
    
    while (1) {
        time_t t = time(NULL);
        struct tm * tm = localtime(&t);
        char * curtime = asctime(tm);
        fwrite(curtime, strlen(curtime), 1, fp);
        fflush(fp);
        sleep(1);
    }
    fclose(fp);

    return 0;
}
