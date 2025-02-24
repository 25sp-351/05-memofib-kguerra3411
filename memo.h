#ifndef CACHE_H
#define CACHE_H

#include "fibonacci.h"

#define MAX_MEMOIZED 91
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define NO_VALUE_YET -1

long_long_func_ptr init_cache(long_long_func_ptr real_provider);

#endif
