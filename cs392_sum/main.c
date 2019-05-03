#include <stdio.h>

int cs392_sum(int op1, int op2); // function from dynamic library

int main() {
    int a = 1;
    int b = 2;
    int c = cs392_sum(a, b);
    printf("The summation is: %d\n", c);
    return 0;
}