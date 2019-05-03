/**
    Title  : CS 392 B - HW Assignment 2
    Desc   : API for string length calculation; implemented as a shared library
    Name   : Bobby Georgiou
    Date   : 03/16/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include "cs392_string.h"

/**
 * Returns the length of a C-style string
 */
unsigned cs392_strlen(char * str) {
    if (str == NULL || str[0] == '\0') {
        return 0;
    }
    str++;
    return 1 + cs392_strlen(str);
}
