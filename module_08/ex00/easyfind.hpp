

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>

int easyfind(T &v, int n)
{
    typename T::iterator it = find(v.begin(), v.end(), n);
    if (it == v.end())
        throw std::out_of_range("Element not found!");
    return std::distance(v.begin(), it);
}

#endif