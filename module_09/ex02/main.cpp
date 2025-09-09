#include "PmergeMe.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <sys/time.h>

long getTimeMs() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./PmergeMe \"num1 num2 num3 ...\"" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe container(argv[1]);
        //container.printVec();
        //container.printDeq();
        
        //std::cout << "After" << std::endl;
        long start = getTimeMs();
        container.pmergeVec();
        long end = getTimeMs();
        //container.printVec();
        std::cout << "Time to process a range of " << "size" << " elements with std::" << "vector : " << start - end << " ms" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}