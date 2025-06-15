#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
//#include <stdexcept>

class Span
{
private:
    std::vector<unsigned int> num;
    int max_size;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    void addNumber(unsigned int n);
    unsigned int shortestSpan();
    unsigned intlongestSpan();
};

#endif