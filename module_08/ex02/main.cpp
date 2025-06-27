#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{

    // MutantStack<int> mstack;
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    // std::cout << mstack.top() << std::endl;
    std::cout << mstack.back() << std::endl;
    mstack.pop_front();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.end();
    std::list<int>::iterator ite = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "in list " << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
    std::list<int> s(mstack);
    return 0;
}