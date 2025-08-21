#include "RPN.hpp"
#include <iostream>
#include <cctype>

// bool isSpace(char c)
// {
//     return (c == ' ' || c == '\t');
// }

// bool charOk(char c)
// {
//     return (c == '+' || c == '-' || c == '*' ||
//             c == '/' || std::isdigit(static_cast<unsigned char>(c))) ||
//            isSpace(c);
// }

// void checkIn(std::string &str)
// {
//     for (size_t i = 0; i < str.size(); i++)
//     {

//         if (!charOk(str[i]))
//         {
//             throw std::runtime_error(std::string("Exception: Wrong char: ") + str[i]);
//         }
//     }
// }

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
        std::cout << "Size arg is " << arg.size() << std::endl;

        //checkIn(arg);
        res.printRes(arg);
        
    }
    catch (const std::exception &e)
    {
        std::cout << "Error in main: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}