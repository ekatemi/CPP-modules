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

bool charOk(char c)
{
    return (std::isdigit(static_cast<unsigned char>(c)) || isOp(c));
}

bool isSpace(char c)
{
    return (c == ' ' || c == '\t');
}

void RPN::fillStack(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isSpace(str[i]))
            i++;
        else if (isdigit(str[i]))
            myStack.push(str[i]);
        else if (isOp)
            calcRes(); // TODO
    }
    if (myStack.size() !=)
}

// methods
int RPN::calcRes(const std::string str)
{
    int num;
    int t1;
    int t2;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(static_cast<unsigned char>(str[i])))
            num = str[i] - '0';
        myStack.push(num);
        else if (str[i] == '-' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int t1 = st.top(); // get top element
            st.pop();
            int t2 = st.top(); // get top element
            st.pop();
            num =
        }
    }
}
