#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq() {}

PmergeMe::PmergeMe(char *input)
{
    std::istringstream iss((std::string(input)));
    long long num;

    while (iss >> num)
    {
        // check for range
        if (num <= 0)
        {
            throw std::runtime_error("Error: only positive integers allowed.");
        }
        if (num > INT_MAX)
        {
            throw std::runtime_error("Error: number too large for int.");
        }

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
    if (!iss.eof())
    {
        throw std::runtime_error("Error: invalid input (non-integer token).");
    }
}

PmergeMe::PmergeMe(const PmergeMe &src) : vec(src.vec), deq(src.deq) {}
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

void PmergeMe::printVec() const
{
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
        std::cout << vec[i] << std::endl;
}
void PmergeMe::printDeq() const
{
    for (int i = 0; i < static_cast<int>(deq.size()); i++)
        std::cout << deq[i] << std::endl;
}

void PmergeMe::pmergeVec()
{
    for (int i = 0; i < vec.size() - 1; i += 2)
    {

        if (vec[i] < vec[i + 1])
        {
            std::swap(vec[i], vec[i + 1]);
        }
    }

    // vector sorted in pairs

    /// other code
}