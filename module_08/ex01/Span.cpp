#include "Span.hpp"
#include <limits>

Span::Span() : max_size(0) {}
Span::Span(unsigned int n) : max_size(n)
{
    if (n > 1000000)
        throw std::logic_error("Suspiciously large Span size — did you pass a negative number?");
}

Span::Span(const Span &src)
{
    // max_size = src.max_size;
    *this = src;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        num = src.num;
        max_size = src.max_size;
    }
    return *this;
}
Span::~Span() {};

void Span::addNumber(int n)
{
    if (num.size() < max_size)
        num.push_back(n);
    else
        throw std::logic_error("No space in vector");
}

void addRange(int *arrNum)
{
    for ()
}

unsigned int Span::longestSpan()
{
    unsigned int res = 0;
    if (num.empty() || num.size() == 1)
        throw std::logic_error("Less than 2 members in vector");
    sort(num.begin(), num.end());
    res = *(num.end() - 1) - *(num.begin());
    return res;
}

unsigned int Span::shortestSpan()
{
    int res = 0;
    if (num.empty() || num.size() == 1)
        throw std::logic_error("Less than 2 members");
    sort(num.begin(), num.end());
    res = num[1] - num[0];
    std::vector<int>::iterator it;
    for (it = num.begin(); it != num.end(); ++it)
    {
        if (it + 1 != num.end() && (*(it + 1) - *it) < res)
        {
            res = *(it + 1) - *it;
        }
    }

    return res;
}
