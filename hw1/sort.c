/**
    Title  : CS 392 B - HW Assignment 1 - Task 2
    Desc   : Given a file of integers, sorts them and outputs them in binary format to a specified output file
    Name   : Bobby Georgiou
    Date   : 02/15/2019
    Pledge : "I pledge my honor that I have abided by the Stevens Honor System."
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "sort.h"

/**
 * Display error message given one of the error types defined in the header
 */
void throw_error(int error_type, int err_no) {
    printf("Error #%d: %s\n", err_no, ERROR_MSG[error_type]);
}

/**
 * Sort integers given an array pointer; uses insertion sort
 */
void sort_ints(int numbers_cnt, int * nums) {
    int outer, current, inner;
    for (outer = 1; outer < numbers_cnt; outer++) {
        current = nums[outer];
        inner = outer - 1;
        while (inner >= 0 && nums[inner] > current) {
            nums[inner + 1] = nums[inner];
            inner--;
        }
        nums[inner + 1] = current;
    }
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        printf("Usage: ./sort <inputfile> <outputfile>\n");
        exit(1);
    }

    // open input file stream
    FILE * fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        throw_error(CANNOT_OPEN, errno);
        exit(1);
    }

    // get file size and allocate memory
    fseek(fp_in, 0L, SEEK_END);
    const int file_size = ftell(fp_in);
    fseek(fp_in, 0L, SEEK_SET);

    char * c = malloc(file_size);
    if (c == NULL) {
        throw_error(MEMORY_ALLOCATION, errno);
        exit(1);
    }

    fread(c, 1, file_size, fp_in);
    fclose(fp_in);

    int cur_index;
    int numbers_cnt = 0;
    char * cur_number = malloc(MAX_INT_LENGTH);
    int cur_number_index = 0;
    int * nums = malloc(file_size);

    // read input and convert to integer array
    for (cur_index = 0; cur_index < file_size; cur_index++) {
        char cur_char = c[cur_index];
        if (cur_char == '\n' && cur_number_index > 0) {
            numbers_cnt++;
            nums[numbers_cnt - 1] = atoi(cur_number);
            cur_number_index = 0;
            cur_number = malloc(MAX_INT_LENGTH); // re-allocate array for next number
        } else if (cur_char != '\n') {
            cur_number[cur_number_index] = cur_char;
            cur_number_index++;
        }
    }
    free(c);
    free(cur_number);

    // sort array of integers by passing pointer
    sort_ints(numbers_cnt, nums);

    // open output file stream
    FILE * fp_out = fopen(argv[2], "wb");
    if (fp_out == NULL) {
        throw_error(CANNOT_OUTPUT, errno);
        exit(1);
    }

    // allocate and build output char array
    char * d = malloc(file_size * 2);
    if (d == NULL) {
        throw_error(MEMORY_ALLOCATION, errno);
        exit(1);
    }

    // output sorted integers
    for (cur_index = 0; cur_index < numbers_cnt; cur_index++) {
        int cur_int = nums[cur_index];
        fwrite(&cur_int, sizeof(int), 1, fp_out);
        fputc('\n', fp_out);
    }

    // free allocated memory
    free(nums);
    fclose(fp_out);
    
    return 0;
}
