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

bool isChar(std::string str)
{
    if (str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}

bool isInt(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
        {
            return false;
        }
    }
    return true;
}

int isDoubleOrFloat(std::string str)
{
    if (str.empty())
        return 0;

    bool has_dot = false;
    bool has_digit = false;
    bool has_f_suffix = false;

    size_t i = 0;

    // Handle optional sign
    if (str[i] == '+' || str[i] == '-')
        i++;

    while (i < str.length())
    {
        if (str[i] == '.')
        {
            if (has_dot) // already found one dot
                return 0;
            has_dot = true;
        }
        else if (str[i] == 'f' && i == str.length() - 1)
        {
            has_f_suffix = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(str[i])))
        {
            has_digit = true;
        }
        else
        {
            return 0; // invalid character
        }
        i++;
    }

    if (!has_digit)
        return 0; // must contain at least one digit

    if (!has_dot)
        return 0; // no dot, not a float or double

    if (has_f_suffix)
        return 2;
    return 1; // 2 = float, 1 = double
}

void ScalarConverter::convert(std::string str)
{
    char c = ' ';
    int i = 42;
    float f = 0.0f;
    double d = 0.0;
    
    if(isChar(str))
    {
        std::cout << "CASE char" <<std::endl;
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if(isInt(str))
    {
        std::cout << "CASE int" <<std::endl;
        i = atoi(str.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if(isDoubleOrFloat(str) == 2) //float
    {
        std::cout << "CASE float" <<std::endl;
        std::string tmp = str.substr(0, str.length() - 1);
        f = stof(tmp);
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(f);
    }
    else if(isDoubleOrFloat(str) == 1) //double
    {
        std::cout << "CASE double" <<std::endl;
        d = atof(str.c_str());
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(d);
    }
    else if (str == "nan" || str == "+inf" || str == "-inf" ){
        std::cout << "char: Impossible" <<std::endl;
        std::cout << "int: Impossible" <<std::endl;
        d = atof(str.c_str());
        f = static_cast<float>(d);
        std::cout << "float: " << f << 'f' << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }
    else if(str == "+inff" || str == "-inff" || str == "nanf") //float
    {
        std::string tmp = str.substr(0, str.length() - 1);
        f = stof(tmp);
        d = static_cast<double>(f);
        std::cout << "char: Impossible" <<std::endl;
        std::cout << "int: Impossible" <<std::endl;
        std::cout << "float: " << f << 'f' << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }
    else
    {
        std::cout << "Arg non convertible" <<std::endl;
        return ;
    }
        
    
    if(!std::isprint(c))
        std::cout << "char: Non Displayable" <<std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    
    if (i > INT_MAX || i < INT_MIN)
        std::cout << "int out of range" << std::endl;
    else
        std::cout << "int: " << i <<std::endl;
    
    if (f > FLT_MAX || f < -FLT_MAX)
        std::cout << "float out of range" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    if (d > DBL_MAX || d < -DBL_MAX)
        std::cout << "double out of range" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}
