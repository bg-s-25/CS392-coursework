/**
    Title  : CS 392 B - HW Assignment 1 - Task 1
    Desc   : Recreation of the cat command of the Unix terminal
    Name   : Bobby Georgiou
    Date   : 02/15/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Given a char pointer, writes its contents to the standard output
 */
void print_to_stdout(char * c, int size) {
    fwrite(c, 1, size, stdout);
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./cat <filename>\n");
        return 1;
    }
    
    // open file stream
    FILE * fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error #%d: Cannot open file.\n", errno);
        return 1;
    }

    // get file size and allocate memory
    fseek(fp, 0L, SEEK_END);
    const int file_size = ftell(fp);
    char * c = malloc(file_size);
    rewind(fp);

    if (c == NULL) {
        printf("Error #%d: Unable to allocate memory.\n", errno);
        return 1;
    }

    fread(c, 1, file_size, fp);
    print_to_stdout(c, file_size); // output to stdout

    // free allocated memory
    free(c);

    // close file stream
    fclose(fp);

    return 0;
}
