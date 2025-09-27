#include "RPN.hpp"
#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: no arguments" << std::endl;
        return 1;
    }

    try
    {
        std::string arg = argv[1];
        RPN res;

        res.printRes(arg);
        
    }
    catch (const std::exception &e)
    {
        std::cout << "Error in main: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}