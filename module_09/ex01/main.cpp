//#include "RPN.hpp"
#include <iostream>
#include <cctype>

bool charOk(char c) {
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || std::isdigit(static_cast<unsigned char>(c)));
}

bool isSpace(char c) {
    return (c == ' ' || c == '\t');
}

void removeSpaces(std::string &str) {
    for (size_t i = 0; i < str.size(); ) {
        if (isSpace(str[i])) {
            str.erase(i, 1);  
        } else if (!charOk(str[i])) {
            throw std::runtime_error(std::string("Wrong char: ") + str[i]);
        } else {
            i++;
        }
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: no arguments" << std::endl;
        return 1;
    }

    try {
        std::string arg = argv[1];
        std::cout << "Size arg is " << arg.size() << std::endl;
        
        removeSpaces(arg);
        
        for (size_t i = 0; i < arg.size(); i++) {
            std::cout << arg[i] << std::endl;
        }
        std::cout << "Size arg is " << arg.size() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}