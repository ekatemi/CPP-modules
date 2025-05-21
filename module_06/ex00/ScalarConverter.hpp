#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

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