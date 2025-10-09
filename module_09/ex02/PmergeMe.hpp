#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> // std::cout
#include <sstream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class PmergeMe
{
private:
    std::vector<unsigned int> vec;
    std::deque<unsigned int> deq;
    std::vector<unsigned int> _j_seq; // for index
    std::vector<unsigned int> jacobstal_seq(unsigned int size);
    unsigned int max;   // for insertion, right is max, second in pair
    unsigned int min;   // for insertion, left is min, first in pair
    unsigned int left;  // jac sequence _j_seq[i]
    unsigned int right; // start fron vec.start() and then moving ->>>  right = left;
    // for recursion visualization
    int depth;

    // size_t size;

public:
    PmergeMe();
    PmergeMe(char *str);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    // methods
    // size_t getSize() const;

    std::vector<unsigned int> getVec() const;
    void printVec(std::string str) const;
    void printDeq(std::string str) const;
    //  void sort();

    void PmergeMeVec();
    void pmergeDeq();
};

#endif
