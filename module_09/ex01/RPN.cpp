#include "RPN.hpp"

RPN::RPN() : myStack() {}
RPN::RPN(const RPN &src) : myStack(src.myStack) {}
RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
        myStack = src.myStack;
    return *this;
}
RPN::~RPN() {}

bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/');
}

bool isSpace(char c)
{
    return (c == ' ' || c == '\t');
}

void RPN::pushStack(char c) {
    int tmp = c - '0';
    myStack.push(tmp); 
}

int RPN::popStack() {
    int i = 0;
    if (!myStack.empty()) {
        i = myStack.top();
        myStack.pop();
    } else 
        throw std::runtime_error("Error: stack is empty (invalid expression)");
    return i;
}

void RPN::calc(char op) {
    if (myStack.size() < 2)
        throw std::runtime_error("not enough operands");
    int b = popStack(); //second operand
    int a = popStack(); //first operand
    int res;

    switch (op)
    {
    case ('+'):
        res = a + b;
        break;
    case ('-'):
        res = a - b;
        break;
    case ('*'):
        res = a * b;
        break;
    case ('/'):
        if (b == 0)
            throw std::runtime_error("Error: Division by 0");
        res = a / b;
        break;
    default:
        throw std::runtime_error(("Error: unrecognised input ") + op);
    }
    myStack.push(res);
}

void RPN::printRes(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if(isSpace(str[i]))
            continue;
        else if (isdigit(str[i]))
            pushStack(str[i]);
        else if (isOp(str[i]))
            calc(str[i]);
        else
            throw std::runtime_error(std::string("Wrong char"));
    }

    if (myStack.size() != 1)
        throw std::runtime_error("no more operators for operands"); //maybe not here
    int res = myStack.top();
    std::cout << res << std::endl;
}
