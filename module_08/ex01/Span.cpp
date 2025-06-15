#include "Span.hpp"
#include <limits>

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

void Span::addNumber(unsigned int n) {
    try {
        if (n > std::numeric_limits<unsigned int>::max())
            throw std::overflow_error("Not unsigned int");

        if (static_cast<int>(num.size()) < max_size)
            num.push_back(n);
        else
            throw std::logic_error("No space in vector");
    }
    catch (const std::overflow_error& e) {
        std::cerr << "Overflow error: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unknown error: " << e.what() << std::endl;
    }
}
   //shortestSpan();
    //longestSpan();
