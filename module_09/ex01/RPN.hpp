#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>       // std::cout
#include <stack>          // std::stack

class RPN {
    private:
        std::stack<int> myStack;
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();

        //methods
        int calcRes(std::string str);
};


#endif

// + - / * 