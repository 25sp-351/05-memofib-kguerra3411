#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"
#include "memo.h"

int main(int argc, char *argv[]) {
    int test_val;

    if (argc < 2) {
        printf("Error: Missing value. Try again.\n");
        return 1;
    }

    if (sscanf_s(argv[1], "%d", &test_val) != 1 || test_val < 0) {
        printf("Error: Please enter a value greater than or equal to zero.\n");
        return 1;
    }

    // PROGRAM INITIALIZATION
    fibonacci_provider = init_cache(fibonacci);

    if (test_val == 0) {
        printf("Fibonacci of 0 is 0\n");
        return 0;
    }
    if (test_val > 91) {
        printf("Fibonacci is a work in progress\n");
        return 0;
    }

    // PROGRAM FUNCTIONALITY
    for (int ix = test_val; ix > 0; ix--) {
        printf("Fibonacci of %d is %lld\n", ix, (*fibonacci_provider)(ix));
    }
    for (int ix = 0; ix < test_val; ix++) {
        printf("Fibonacci of %d is %lld\n", ix, (*fibonacci_provider)(ix));
    }

    return 0;
}
