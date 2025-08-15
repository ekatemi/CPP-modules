#include "BitcoinExchange.hpp"
#include "BitcoinExchange.cpp"
#include <stdexcept>
#include <iomanip> 

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



float toFloatConverter(std::string str)
{
    char *end;
    double num = std::strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\0') //maybe no need to check it
        return -3;
    return num;
}


void trimInPlace(std::string &str) {
    // Remove leading spaces
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) {
        str.clear(); // all spaces
        return;
    }

    // Remove trailing spaces
    size_t end = str.find_last_not_of(" \t\r\n");

    // Erase characters before and after the valid range
    str.erase(end + 1);
    str.erase(0, start);
}

//split data and price
void parseInput(std::string line, std::string &date, std::string &val)
{
    size_t del = line.find('|'); //split |    2011-01-03 and 3
    
    if (del == std::string::npos)
    {
        std::cout << "Error: wrong format => " << line << std::endl;
        return ;
    }
    
    date  = line.substr(0, del); //2011-01-03
    val = line.substr(del + 1); // 3
    trimInPlace(date);
    trimInPlace(val);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "wrong args" << std::endl;
        return 1;
    }
    BitcoinExchange in;
    std::string file = argv[1];

    std::ifstream infile(file.c_str());

    std::ifstream db("data.csv");
    
    std::map<std::string, float> dataBase;
    
    if (!db) {
        std::cerr << "Failed to open file: " << "data.csv" << std::endl;
        return 1;
    }

    if (!infile) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return 1;
    }

    

    std::string line;
    std::getline(db, line); //to skip first line
    while (std::getline(db, line)) { //.cvs handling
        
        if (line.empty()) continue; //skip empty line
        //assuming db is correct no checks

        size_t del = line.find(',');
        std::string date;
        std::string val;

        if (del == std::string::npos)
        {
            std::cout << "Error: wrong format => " << line << std::endl;
            return 1;
        }
        date  = line.substr(0, del);
        val = line.substr(del + 1);
        //std::cout << line << std::endl;
        dataBase[date] = toFloatConverter(val); //fill db
    }


    while (std::getline(infile, line)) { //input file handling
        std::string date;
        std::string val;
        parseInput(line, date, val);
        in.setDate(date);
        in.setVal(toFloatConverter(val));
        in.searchMap(dataBase);
    

        //std::cout << line << std::endl;
    }

    // std::string queryDate = "2009-01-05";
    // std::cout << "entry 2009-01-02 =>" << std::fixed << std::setprecision(2) << dataBase[queryDate] << std::endl;
    return 0;
}

