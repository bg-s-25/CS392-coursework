/**
    Title  : CS 392 B - HW Assignment 3
    Desc   : Fork and execute a shell command inside a child process
    Name   : Bobby Georgiou
    Date   : 04/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "cs392_exec.h"

/**
 * Fork child process and run given shell command with provided arguments
 */
void fork_exec(char * command) {
    char * args = strtok(command, " ");

    // split command into arguements
    char * argv[64];
    int cnt = 0;
    while (args != NULL) {
        argv[cnt] = args;
        args = strtok(NULL, " "); // increment args to next available argument
        cnt++;
    }
    argv[cnt] = NULL;

    // fork child process and execute command
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // child process action
        execvp(argv[0], argv);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
    }
}
