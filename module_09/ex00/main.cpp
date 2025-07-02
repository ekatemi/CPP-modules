#include "BitcoinExchange.hpp"
#include <iostream>

//correct format 2009-01-05,0
//check year > 2009-01-03(creation bitcoin)
//           < today date 2025-07-03
// 2009 <= year <= 2025
// 1 <= month <= 12
// jan, mar, may, july, aug, oct, dec  1 <= day <= 31 //1,3,5,7,8,10,12
// apr, june, sept, nov 1 <= day <= 30 //2,4,6,9,11
// feb if isLeap 1-29, otherwise 1-28 

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
    }

    return 0;
}

