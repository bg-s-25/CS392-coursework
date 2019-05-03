/**
    Title  : CS 392 B - HW Assignment 2
    Desc   : API for memory copy; implemented as a shared library
    Name   : Bobby Georgiou
    Date   : 03/16/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include "cs392_string.h"

/**
 * Copies num bytes from src to dst using pointer casting
 */
void * cs392_memcpy(void * dst, void * src, unsigned num) {
    if (src == NULL) {
        printf("Error: Source is null.");
        return NULL;
    }

    char * dst_arr = dst; // char pointer points to dst
    char * src_arr = (char *)src; // cast src pointer

    int memcnt;
    for (memcnt = 0; memcnt < num; memcnt++) { // copy num bytes
        dst_arr[memcnt] = src_arr[memcnt];
    }
    
    return dst_arr;
}
