#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> // std::cout
#include <vector>
#include <deque>

class PmergeMe
{
private:
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;

public:
    PmergeMe();
    PmergeMe(std::string str);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    // methods

};

#endif

