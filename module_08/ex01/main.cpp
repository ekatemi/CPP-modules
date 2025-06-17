#include "Span.hpp"
int main()
{
    Span sp = Span(5); // 3 6 9 11 17
    sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    std::cout << "Hola" << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}