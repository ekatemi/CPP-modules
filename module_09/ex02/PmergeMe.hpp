#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> // std::cout
#include <sstream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <climits>

class PmergeMe
{
private:
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;
    //unsigned long size;

public:
    PmergeMe();
    PmergeMe(char *str);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    // methods
    //long getSize() const;
    void printVec(std::string str) const;
    void printDeq() const;

    void pmergeVec();
};

#endif
