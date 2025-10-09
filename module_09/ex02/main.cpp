#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <sys/time.h>

long getTimeMs()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./PmergeMe \"num1 num2 num3 ...\"" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe container(argv[1]);
        long start = getTimeMs();
        const std::vector<unsigned int> vec = container.getVec();
        container.printVec("Before: ");
        container.PmergeMeVec();
        container.printVec("After: ");
        long end = getTimeMs();
        double duration_us = double(end - start) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::" << "vector : "
                  << std::fixed << std::setprecision(0) << duration_us << " us" << std::endl;

        // start = getTimeMs();
        // container.pmergeDeq();
        // end = getTimeMs();
        // duration_us = double(end - start) / CLOCKS_PER_SEC * 1e6;
        // std::cout << "Time to process a range of " << container.getSize() << " elements with std::" << "deque : " << duration_us << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

//./PmergeMe "$(for i in $(seq 1 1000); do echo -n "$((RANDOM % 10000 + 1)) "; done)"