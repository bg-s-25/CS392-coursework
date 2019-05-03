#define TRUE 1
#include <stdio.h>

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./file_size <filename>\n");
        return 1;
    }

    // Print file size in bytes

    FILE * fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    const int file_size = ftell(fp); // size of file in bytes

    printf("\nFile size: %d", file_size);
    printf("\n");
    fclose(fp);
    return 0;
}
