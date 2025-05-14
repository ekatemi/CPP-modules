#include "ScalarConverter.hpp"

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
    float f = 0.0;
    double d = 0.0;
    int i = 0;
    char c = ' ';

    if (str[str.length() - 1] == 'f')
        str = str.substr(0, str.length() - 1);

    try
    {
    }
    f = static_cast<float>(atof(str.c_str()));
    d = static_cast<double>(f);
    i = static_cast<int>(f);
    c = static_cast<char>(i);

    if (!isprint(c))
        std::cout << "char: " << "Non displayable" << std::endl;
    else if (str == "nan")
        std::cout << "char: " << "Impossible" << std::endl;
    else
        std::cout << "char: " << "'" << c << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << d << std::endl;

    //  std::cout << "float: " << static_cast<int>(str) << std::endl;
    //  std::cout << "double: " << static_cast<int>(str) << std::endl;
}
