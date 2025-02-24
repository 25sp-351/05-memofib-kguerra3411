#include <stdio.h>
#include "memo.h"

long_long_func_ptr _original_provider;
long long _memoization_data[ARRAY_SIZE];

long long cache_func(int n) {
    printf(__FILE__ ":%2d   cache_func(%d) called\n", __LINE__, n);

    if (n > MAX_MEMOIZED)
        return (*_original_provider)(n);

    if (_memoization_data[n] == NO_VALUE_YET)
        _memoization_data[n] = (*_original_provider)(n);

    return _memoization_data[n];
}

long_long_func_ptr init_cache(long_long_func_ptr real_provider) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++)
        _memoization_data[ix] = NO_VALUE_YET;

    _original_provider = real_provider;
    return cache_func;
}
