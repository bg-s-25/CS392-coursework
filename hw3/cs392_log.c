/**
    Title  : CS 392 B - HW Assignment 3
    Desc   : Write shell command history to "cs392_shell.log"
    Name   : Bobby Georgiou
    Date   : 04/07/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs392_log.h"

/**
 * Log command by appending to log file
 */
void log_command(char * command) {
    // create or open log file for appending
    FILE * fp = fopen("cs392_shell.log", "a");
    if (fp == NULL) {
        printf("Error: Cannot create or open log file.\n");
        exit(1);
    }

    fwrite(command, strlen(command), 1, fp);
    fwrite("\n", 1, 1, fp);
    fclose(fp);
}
