#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

class ScalarConverter
{

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);

public:
    ScalarConverter &operator=(const ScalarConverter &src);
    virtual ~ScalarConverter();
    static void convert(std::string str);
};

#endif