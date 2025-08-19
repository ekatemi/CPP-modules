#include "RPN.hpp"

RPN::RPN() : myStack() {}
RPN::RPN(const RPN &src) : myStack(src.myStack){}
RPN &RPN::operator=(const RPN &src){
    if (this != &src)
        myStack = src.myStack;
    return *this;
}
RPN::~RPN() {}

//methods
int RPN::calcRes(const std::string str) {
    int num;
    int t1;
    int t2;
    for(int i = 0; i < str.size(); i++) {
        if (isdigit(static_cast<unsigned char>(str[i])))
            num = str[i] - '0';
        myStack.push(num);
        else if (str[i] == '-' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int t1 = st.top(); // get top element
            st.pop();
            int t2 = st.top(); // get top element
            st.pop();
            num = 
        }
    }
}



