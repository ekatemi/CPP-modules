#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
    std::vector<int> num;
    int max_size;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();
};

#endif