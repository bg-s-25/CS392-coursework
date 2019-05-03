/**
    CS 392 Midterm
    Name   : Bobby Georgiou
    Date   : 03/06/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdlib.h>
#include "cs392_midterm.h"

/**
 * Appends string src string to dest string, using at most n bytes from src
 */
char * cs392_strncat(char * dest, char * src, unsigned n) {
    int index_dest = 0; // index in dest
    while (dest[index_dest] != '\0') {
        index_dest++;
    }

    int index_src; // index in src

    // iterate and set at most n bytes
    for (index_src = 0; index_src < n; index_src++) {
        if (src[index_src] == '\0') break;
        dest[index_dest] = src[index_src];
        index_dest++;
    }
    dest[index_dest] = '\0'; // append null byte

    return dest;
}
