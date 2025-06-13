#include "Span.hpp"

Span::Span() : max_size(0) {}
Span::Span(unsigned int n) : max_size(n) {}
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
