#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): vec(), deq() {}
PmergeMe::PmergeMe(): vec(), deq() {}
PmergeMe::PmergeMe(const PmergeMe &src): vec(src.vec), deq(src.deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        vec = src.vec;
        deq = src.deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}
