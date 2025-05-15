#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter
{

    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    virtual ~ScalarConverter() = 0;
    // char int float double
    static void convert(std::string str);
};