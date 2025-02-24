#ifndef FIBONACCI_H
#define FIBONACCI_H

typedef long long (*long_long_func_ptr)(int param);

extern long_long_func_ptr fibonacci_provider;

long long fibonacci(int n);

#endif
