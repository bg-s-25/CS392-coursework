/**
    CS 392 Midterm
    Name   : Bobby Georgiou
    Date   : 03/06/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdlib.h>
#include "cs392_midterm.h"

/**
 * Copies the string in src to dest
 */
char * cs392_strcpy(char * dest, char * src) {
    int index = 0;

    // iterate and set bytes until null byte is read
    while (src != NULL) {
        dest[index] = src[index];
        if (src[index] == '\0') break;
        index++;
    }

    return dest;
}
