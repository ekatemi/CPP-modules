#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <cerrno>

ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; };
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
    {
    }
    return (*this);
}
ScalarConverter::~ScalarConverter() {};
// char int float double

// int parseStr(std::string str)
// {
//     int found = str.find('.');
//     if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
//         return 1;
//     else if (str[str.length() - 1] == 'f' && found != std::string::npos)
//         return 2;
//     else if (found != std::string::npos && found != 0 && found != str.length() - 1)
//         return 3;
// }

// void convertToChar(std::string str)
// {
//     if (str[str.length() - 1] == 'f')
//         str = str.substr(0, str.length() - 1);

//     float f = static_cast<float>(atof(str.c_str()));
//     double d = static_cast<double>(f);
//     int i = static_cast<int>(i);
//     char c = static_cast<char>(c);

//     // if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
//     // {
//     //     std::cout << "'" << str[0] << "'" << std::endl;
//     // }
//     // else
//     // else
//     // {
//     //     try
//     //     {
//     //         int num = stoi(str);
//     //         char ch = static_cast<char>(num);
//     //         if (!isprint(ch))
//     //             std::cout << "non displayable" << std::endl;
//     //         else
//     //             std::cout << "'" << ch << "'" << std::endl;
//     //     }
//     //     catch (const std::invalid_argument &e)
//     //     {
//     //         std::cout << "impossible" << std::endl;
//     //     }
//     //     catch (const std::out_of_range &e)
//     //     {
//     //         std::cout << "argument out of range" << std::endl;
//     //     }
//     // }
// }

void ScalarConverter::convert(std::string str)
{  
    
    if (str[str.length() - 1] == 'f')
        str = str.substr(0, str.length() - 1);
    std::cout << "String is: " << str << std::endl;
    
    errno = 0;
    char* endPtr;
    double d = strtod(str.c_str(), &endPtr);

    if (errno == ERANGE)
    {
        std::cout << "Input err: overflow or underflow" << std::endl;
        return ;
    }     
    else if (endPtr == str.c_str() || *endPtr != '\0')
    {
        std::cout << "Input err: invalid input" << std::endl;\
        return ;
    }   
    else {
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return ;
    }
    //     std::cout << "double: " << d << std::endl;
    float f = static_cast<float>(d);
    // if (!std::isfinite(f)) {
    //     std::cout << "Hello inf" << std::endl;
    // }

    // if (str[str.length() - 1] == 'f')
    //     str = str.substr(0, str.length() - 1);
    // std::cout << "String is: " << str << std::endl;
    
    // if (str == "inf" || str == "+inf" || str == "in" 
    //     || str == "+in" || str == "-inf" || str == "-in")
    // {
    //     std::cout << "char: Impossible" << std::endl;
    //     std::cout << "int: Impossible" << std::endl;
    //     std::cout << "float: " << str << "f" << std::endl;
    //     std::cout << "double: " << str << "f" << std::endl;
    //     return ;
    // }

    
    
    
    
    // int i = static_cast<int>(f);
    // char c = static_cast<char>(i);

    // if (d != d)
    // {
    //     std::cout << "char: Impossible" << std::endl;
    //     std::cout << "int: Impossible" << std::endl;
    //     std::cout << "float: nanf" << std::endl;
    //     std::cout << "double: nan" << std::endl;
    //     return;
    // }

    // if (!std::isprint(c))
    //     std::cout << "char: Non displayable" << std::endl;
    // else
    //     std::cout << "char: '" << c << "'" << std::endl;
    
    
    // std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
