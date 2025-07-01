#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    /*empty size back push_back pop_back*/
    
    std::cout << "\033[32m*** MUTANT ***\033[0m" << std::endl;
    MutantStack<int> mstack;
    if(mstack.empty()){
        std::cout << "container empty" << std::endl;
    }

    mstack.push(5); //adds at the top -> 5
    mstack.push(17); // -> 5 17
    std::cout << mstack.top() << std::endl; //shows last added on top  -> shows 17 ---------
    mstack.pop(); //removes 1st element  -> removes 17
    std::cout << mstack.size() << std::endl; //number of elements at stack  -> 1 ----------
    mstack.push(3); //  -> 5 3
    mstack.push(5); //  -> 5 3 5
    mstack.push(737); //  -> 5 3 5 737
    //[...]
    mstack.push(0); // -> 5 3 5 737 0 
    std::cout << "\033[32m reverse iterator \033[0m" << std::endl;
    MutantStack<int>::reverse_iterator beg = mstack.rbegin();
    MutantStack<int>::reverse_iterator end = mstack.rend();
    while (beg != end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it; 
    --it; //same place
    std::cout << "\033[32m forward iterator \033[0m" << std::endl;
    while (it != ite)
    {
    std::cout << *it << std::endl; // -> 5 3 5 737 0 --------------
    ++it;
    }
    std::stack<int> s(mstack);
    
    
    std::cout << "\033[32m*** LIST ***\033[0m" << std::endl;
    std::list<int> lstack;
    if(lstack.empty()){
        std::cout << "container empty" << std::endl;
    }
    lstack.push_back(5); // -> 5
    lstack.push_back(17); // -> 5 17
    std::cout << lstack.back() << std::endl; // ------------------------
    lstack.pop_back(); // -> removes 17
    std::cout << lstack.size() << std::endl; // -> 1 -------------------
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    //reverse iterators
    lstack.push_back(0);
    std::cout << "\033[32m reverse iterator \033[0m" << std::endl;
    std::list<int>::reverse_iterator rit_b = lstack.rbegin();
    std::list<int>::reverse_iterator rit_e = lstack.rend();
    while (rit_b != rit_e)
    {
        std::cout << *rit_b << std::endl;
        ++rit_b;
    }

    std::list<int>::iterator it_l = lstack.begin();
    std::list<int>::iterator ite_l = lstack.end();
    ++it;
    --it;
    std::cout << "\033[32m forward iterator \033[0m" << std::endl;
    while (it_l != ite_l)
    {
        std::cout << *it_l << std::endl;
        ++it_l;
    }
    std::list<int> l(lstack);
    return 0;
}