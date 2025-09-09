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

void PmergeMe::printVec(std::string str) const
{
    std::cout << str;
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::printDeq() const
{
    for (int i = 0; i < static_cast<int>(deq.size()); i++)
        std::cout << deq[i] << std::endl;
}

//helper

std::vector<int> makePair(int i, int j)
{
    std::vector<int> pair;
    pair.push_back(i);
    pair.push_back(j);
    return pair;
}

void PmergeMe::pmergeVec()
{
    std::vector< std::vector<int> > main;
    printVec("Before: ");
    
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1])
            std::swap(vec[i], vec[i + 1]); // ensure big first
        std::vector<int> pair = makePair(vec[i], vec[i + 1]);
        main.push_back(pair);
    }

    // Handle odd leftover
    if (vec.size() % 2 != 0) {
        std::vector<int> pair = makePair(vec.back(), 0);
        main.push_back(pair);
    }

    std::sort(main.begin(), main.end());
    
    std::vector<unsigned int> sorted;

    for (size_t i = 0; i < main.size(); i++)
        sorted.push_back(main[i][0]); // bigs

// 2. Insert smalls before their own bigs
    for (size_t i = 0; i < main.size(); i++) {
        int big = main[i][0];
        int small = main[i][1];

        if (small == 0) continue; // skip sentinel

        std::vector<unsigned int>::iterator bigPos = std::find(sorted.begin(), sorted.end(), big);
        std::vector<unsigned int>::iterator insertPos = std::lower_bound(sorted.begin(), bigPos, small);
        sorted.insert(insertPos, small);
}

// 3. Copy back to vec
    vec = sorted;
    printVec("After: ");
   
    
}