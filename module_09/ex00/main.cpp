#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

//correct format 2009-01-05,0
//check year > 2009-01-03(creation bitcoin)
//           < today date 2025-07-03
// 2009 <= year <= 2025
// 1 <= month <= 12
// jan, mar, may, july, aug, oct, dec  1 <= day <= 31 //1,3,5,7,8,10,12
// apr, june, sept, nov 1 <= day <= 30 //2,4,6,9,11
// feb if isLeap 1-29, otherwise 1-28 



//convert substring to int or not
//also date can be only positive
double toFloatConverter(std::string str)
{
    char *end;
    double num = std::strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\n' || num < 0)
        return -1;
    return (num);
}

bool isVal(std::string str)
{
    float val = toFloatConverter(str);
    return (val >= 0 && val <= 1000); 
}

bool isLeap(int year)
{
    return (((year % 4 == 0) && 
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

bool isValidYear(int yr) {
    return ( yr >= 2009 && yr <= 2025);
}

bool isValidDay(int day, int yr, int mth) {
    if(mth == 4 || mth == 6 || mth == 9 || mth == 11)
        return (day >= 1 && day <= 30);
    else if (mth == 2 && !isLeap(yr))
    {
        return (day >= 1 && day <= 28);
    }
    else if (mth == 2 && isLeap(yr))
    {
        return (day >= 1 && day <= 29);
    }
    else
        return (day >= 1 && day <= 31);
}

bool isValidMonth(int mth) {
        return (mth >= 1 && mth <= 12);
}


bool parseDate(std::string line)
{
    size_t firstDash = line.find('-');
    size_t secondDash = line.find('-', firstDash + 1);

    std::string year  = line.substr(0, firstDash);
    int yr = toFloatConverter(year);
    
    std::string month = line.substr(firstDash + 1, secondDash - firstDash - 1);
    int mth = toFloatConverter(year);

    std::string day = line.substr(secondDash + 1);
    int d = toFloatConverter(day);
    
    return (isValidYear(yr) && isValidMonth(mth) && isValidDay(d, yr, mth));
}
//split data and price
void parseString(std::string line, std::string &key, float &value)
{
    std::string date;
    std::string val;
    size_t del = line.find('|');
    
    if (del == std::string::npos)
    {
        std::cout << "Error: wrong format => " << line << std::endl;
        return ;
    }
    
    date  = line.substr(0, del);
    if(parseDate(date))
    
    val = line.substr(del + 1);
    if(isVal(val))

}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "wrong args" << std::endl;
        return 1;
    }

    std::string file = argv[1];
    std::ifstream infile(file.c_str());

    if (!infile) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return 1;
    }

    std::string line;
    
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
        if (parseDate())
    }

    return 0;
}

