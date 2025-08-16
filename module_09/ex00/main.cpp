#include "BitcoinExchange.hpp"

#include <stdexcept>
#include <iomanip> 

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
bool parseInput(std::string line, std::string &date, std::string &val)
{
    size_t del = line.find('|'); //split 2011-01-03 | 3  to  '2011-01-03' and '3'
    
    if (del == std::string::npos)
    {
        std::cout << "Error: wrong format => " << line << std::endl;
        return false;
    }
    
    date  = line.substr(0, del); //2011-01-03
    val = line.substr(del + 1); // 3
    trimInPlace(date);
    trimInPlace(val);
    //std::cout << "TRIMMED[" << date << "] [" << val << "]\n";
    return true;
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
            std::cout << "Error: wrong format db => " << line << std::endl;
            return 1;
        }
        date  = line.substr(0, del);
        val = line.substr(del + 1);
        //std::cout << line << std::endl;
        dataBase[date] = toNumConverter<float>(val); //fill db
    }


    while (std::getline(infile, line)) { //input file handling
        if (line.empty()) continue;
        std::string date = "";
        std::string val = "";
        if (parseInput(line, date, val))
        {
            //std::cout << "[" << date << "] [" << val << "]\n";
            in.setDate(date);
            in.setVal(toNumConverter<float>(val));
            in.searchDb(dataBase);
        }

    

        //std::cout << line << std::endl;
    }

    // std::string queryDate = "2009-01-05";
    // std::cout << "entry 2009-01-05 =>" << std::fixed << std::setprecision(2) << dataBase[queryDate] << std::endl;
    return 0;
}

