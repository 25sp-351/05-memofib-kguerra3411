#include <stdio.h>
#include "fibonacci.h"

long_long_func_ptr fibonacci_provider;

long long fibonacci(int n) {
    printf(__FILE__ ":%2d   fibonacci(%d) called\n", __LINE__, n);

    if (n <= 1)
        return n;

    return (*fibonacci_provider)(n - 1) + (*fibonacci_provider)(n - 2);
}
