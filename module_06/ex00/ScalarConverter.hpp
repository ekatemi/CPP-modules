#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    virtual ~ScalarConverter();
    // char int float double
    static void convert(std::string str);
};