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

void convertToChar(std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
    {
        std::cout << "'" << str[0] << "'" << std::endl;
    }
    else
    {
        try
        {
            int num = stoi(str);
            char ch = static_cast<char>(num);
            if (!isprint(ch))
                std::cout << "non displayable" << std::endl;
            else
                std::cout << "'" << ch << "'" << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "impossible" << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "argument out of range" << std::endl;
        }
    }
}

void ScalarConverter::convert(std::string str)
{

    std::cout << "char: ";
    convertToChar(str);

    // std::cout << "int: " << static_cast<int>(str) << std::endl;
    //  std::cout << "float: " << static_cast<int>(str) << std::endl;
    //  std::cout << "double: " << static_cast<int>(str) << std::endl;
}
