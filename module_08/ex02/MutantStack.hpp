#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>

#include <deque>
#include <list>
#include <iterator>

template <typename T>

class MutantStack : public std::stack<T>
{

public:
    MutantStack() : std::stack<T>() {};
    MutantStack(const MutantStack &src) : std::stack<T>(src) {};
    MutantStack &operator=(const MutantStack &src)
    {
        if (this != &src)
        {
            std::stack<T>::operator=(src);
        }
        return *this;
    }
    ~MutantStack() {};
    // iterators
    // std::iterator it;
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const iterator begin() const { return this->c.begin(); }
    const iterator end() const { return this->c.end(); }

    iterator rbegin() { return this->c.rbegin(); }
    iterator rend() { return this->c.rend(); }
    const iterator rbegin() const { return this->c.rbegin(); }
    const iterator rend() const { return this->c.rend(); }
};
// class MutantStack : public std::stack<T>
// {
// public:
//     // Types for iterator compatibility
//     typedef typename std::stack<T>::container_type::iterator iterator;
//     typedef typename std::stack<T>::container_type::const_iterator const_iterator;
//     typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
//     typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

//     // Constructors and assignment
//     MutantStack() {}
//     MutantStack(const MutantStack& other) : std::stack<T>(other) {}
//     MutantStack& operator=(const MutantStack& other)
//     {
//         std::stack<T>::operator=(other);
//         return *this;
//     }
//     ~MutantStack() {}

//     // Iterator access
//     iterator begin() { return this->c.begin(); }
//     iterator end() { return this->c.end(); }
//     const_iterator begin() const { return this->c.begin(); }
//     const_iterator end() const { return this->c.end(); }

//     reverse_iterator rbegin() { return this->c.rbegin(); }
//     reverse_iterator rend() { return this->c.rend(); }
//     const_reverse_iterator rbegin() const { return this->c.rbegin(); }
//     const_reverse_iterator rend() const { return this->c.rend(); }
// };
#endif