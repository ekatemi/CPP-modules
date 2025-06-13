#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *arr, size_t len, Func fun)
{
    for (size_t i = 0; i < len; ++i)
    {
        fun(arr[i]);
    }
}

template <typename T>
void allPrint(T el)
{
    std::cout << el;
}

#endif