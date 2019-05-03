#include <stdio.h>

int main(int argc, char ** argv) {
    char str[20];
    printf("Enter name: ");
    scanf("%s", str); // input, separated by ENTER
    printf("Hello, %s\n", str);

    int get = getchar();
    printf("Received char: %c", get);

    return 0;
}
