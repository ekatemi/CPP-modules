#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>

template <typename T, typename Func>

void iter(T *arr, size_t len, Func fun)
{
    for (size_t i = 0; i < len; ++i)
    {
        fun(arr[i]);
    }
}

#endif