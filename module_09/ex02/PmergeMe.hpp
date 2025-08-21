#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> // std::cout
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe
{
private:
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;

public:
    PmergeMe();
    PmergeMe(char *str);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    // methods
    void printVec() const;
    void printDeq() const;

};

#endif

