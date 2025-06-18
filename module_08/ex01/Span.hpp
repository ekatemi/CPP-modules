#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
// #include <stdexcept>

class Span
{
private:
    std::vector<int> num;
    unsigned int max_size;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    void addNumber(int n);
    void addRange(int *arrNum);
    // void addRandomRange();
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif