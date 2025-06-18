#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>

int easyfind(T &container, int n)
{
    typename T::iterator it = find(v.begin(), v.end(), n);
    if (it == v.end())
        throw std::runtime_error("Element not found!");
    return std::distance(v.begin(), it);
}

#endif