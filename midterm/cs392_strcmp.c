/**
    CS 392 Midterm
    Name   : Bobby Georgiou
    Date   : 03/06/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdlib.h>
#include "cs392_midterm.h"

/**
 * Compares two strings s1 and s2 and returns an integer representing their relative lengths
 */
int cs392_strcmp(char * s1, char * s2) {
    int index = 0;

    while (s1[index] != '\0' || s2[index] != '\0') { // iterate through all of s1 or s2
        if ((unsigned char)s1[index] > (unsigned char)s2[index]) { // compare ASCII values
            return 1;
        } else if ((unsigned char)s1[index] < (unsigned char)s2[index]) {
            return -1;
        }
        index++;
    }

    if (s2[index] != '\0') { // s2 has greater length
        return 1;
    } else if (s2[index] == '\0' && s1[index] != '\0') { // s1 has greater length
        return -1;
    }

    // s1 and s2 contain the same string
    return 0;
}
