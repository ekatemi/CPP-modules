#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> // std::cout
#include <stack>    // std::stack
#include <sstream>
#include <algorithm>

class RPN
{
private:
    std::stack<int> myStack;

public:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    ~RPN();

    // methods
    void pushStack(char c);
    int popStack();
    void calc(char op);
    void printRes(std::string str);
};

#endif

// + - / *