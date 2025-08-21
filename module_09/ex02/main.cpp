#include "PmergeMe.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./PmergeMe \"num1 num2 num3 ...\"" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe container(argv[1]);
        container.printVec();
        container.printDeq();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}