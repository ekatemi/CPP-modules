#include "Span.hpp"
#include <ctime> 
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

void Span::addNumber(int n)
{
    if (num.size() < max_size)
        num.push_back(n);
    else
        throw std::logic_error("No space in vector");
}

// void Span::addRange(int *arrNum)
// {
//     std::copy(arrNum, arrNum + num.size(), num.begin());
// }

int RandomNumber () { return (std::rand()%1000); }

void Span::addRandomRange()
{
    unsigned int remaining = max_size - num.size();
    if (remaining == 0)
        return; // nothing to do

    std::srand(static_cast<unsigned>(std::time(0)));

    std::vector<int> randomVector(remaining);//create vector of size of empty slots
    std::generate(randomVector.begin(), randomVector.end(), RandomNumber); //fill it with random numbers

    // Append generated numbers to num (don't exceed max_size)
    num.insert(num.end(), randomVector.begin(), randomVector.end());
}

unsigned int Span::longestSpan()
{
    if (num.empty() || num.size() == 1)
        throw std::logic_error("Less than 2 members in vector");
    //previous v
    // sort(num.begin(), num.end());
    // res = *(num.end() - 1) - *(num.begin());
    
    //with algorithms
    int minVal = *std::min_element(num.begin(), num.end());
    int maxVal = *std::max_element(num.begin(), num.end());
    return maxVal - minVal;
}

unsigned int Span::shortestSpan()
{
    int res = 0;
    if (num.size() < 2)
        throw std::logic_error("Less than 2 members");
    std::vector<int> sorted = num;
    std::sort(sorted.begin(), sorted.end());
    res = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < res)
            res = diff;
    }
    return res;
}

void Span::getNum() const {
    std::vector<int>::const_iterator it;
    for (it = num.begin(); it != num.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
