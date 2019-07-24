/**
    Title  : CS 392 B - HW Assignment 3
    Desc   : Interactive shell with signal handler and logging for inputted commands
    Name   : Bobby Georgiou
    Date   : 04/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

int main() {
    // register signal handlers
    register_handlers();

    while (1) {
        printf("cs392_shell$: ");
        char input_str[64];

        // get input from stdin and set buffer
        fgets(input_str, sizeof(input_str), stdin);

        // remove trailing newline character
        input_str[strcspn(input_str, "\n")] = 0;

        // save command to log
        if (input_str[0] != 0) log_command(input_str);

        // check for exit call
        if (strcmp(input_str, "exit") == 0) exit(0);

        // fork process and execute shell command
        fork_exec(input_str);

        int cnt = 0;
        while (input_str[cnt] != 0 && input_str != NULL) {
            input_str[cnt] = 0;
            cnt++;
        }
    }

    return 0;
}
