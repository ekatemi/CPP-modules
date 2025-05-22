#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <cerrno>
#include <cfloat>
#include <climits>

ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; };
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
    {
        // do nothing
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

    // if (str[str.length() - 1] == 'f' && (str != "inf"))
    //     str = str.substr(0, str.length() - 1);

    std::cout << "String is: " << str << std::endl;

    // Reset errno before conversion
    errno = 0;
    char *endPtr = NULL;

    double d = strtod(str.c_str(), &endPtr);
    std::cout << "double is: " << std::fixed << std::setprecision(1) << d << std::endl;
    std::cout << "endptr: " << *endPtr << std::endl;
    if (d == HUGE_VAL)
        std::cout << "too big" << std::endl;
    else if (d == -HUGE_VAL)
        std::cout << "too small" << std::endl;
    float f = static_cast<float>(d);
    std::cout << "float is " << f << std::endl;
    int i = static_cast<int>(f);
    std::cout << "int is " << i << std::endl;
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "out of int" << std::endl;
    char c = static_cast<char>(i);
    std::cout << "char is " << c << std::endl;
    // // Check if any conversion happened
    // if (endPtr == str.c_str())
    // {
    //     std::cout << "invalid input (no conversion to double)" << std::endl;
    //     return;
    // }
    // // Check if the whole string was converted
    // else if (*endPtr != '\0')
    // {
    //     std::cout << "invalid input (leftover characters)" << std::endl;
    //     return;
    // }

    // // Check for overflow/underflow
    // if (errno == ERANGE)
    // {
    //     std::cout << "double: out of range" << std::endl;
    //     return;
    // }

    // // Passed all checks
    // // std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    // if (d > FLT_MAX || d < -FLT_MAX)
    // {
    //     // Overflow for float
    //     std::cout << "float: overflow (infinity)" << std::endl;
    //     return;
    //     // } else if (std::isnan(d)) {
    //     //     // Handle NaN if you want
    //     //     std::cout << "float: nanf" << std::endl;
    // }
    // else
    // {
    //     f = static_cast<float>(d);
    // }
    // if (d > INT_MAX || d < INT_MIN)
    // {
    //     // Overflow would occur if you cast d to int
    //     std::cout << "int: Impossible" << std::endl;
    // }
    // else
    // {
    //     i = static_cast<int>(d);
    // }

    // c = static_cast<char>(i);
    // if (d != d)
    //     std::cout << "char: Impossible" << std::endl;
    // else if (!std::isprint(c))
    //     std::cout << "char: Non displayable" << std::endl;

    // else
    //     std::cout << "char: '" << c << "'" << std::endl;

    // if (d > INT_MAX || d < INT_MIN || d != d)
    // {
    //     // Overflow would occur if you cast d to int
    //     std::cout << "int: Impossible" << std::endl;
    // }
    // else
    // {
    //     i = static_cast<int>(d);
    //     std::cout << "int: " << i << std::endl;
    // }

    // std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    // std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
