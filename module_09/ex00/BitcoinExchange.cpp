#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _db() {}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
    std::ifstream db(file_name.c_str());

    if (!db.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;

    std::getline(db, line); // to skip first line with date | value
    while (std::getline(db, line))
    {
        if (line.empty())
            continue; // skip empty line

        size_t del = line.find(',');
        std::string date;
        std::string val;

        if (del == std::string::npos)
        {
            throw std::runtime_error("Error: wrong format db => " + line);
        }
        date = line.substr(0, del);
        
        if (date.size() != 10)
            throw std::runtime_error("Error: wrong format db => " + line);
        
        val = line.substr(del + 1);
        _db[date] = toNumConverter<float>(val); // fill db
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db(src._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        _db = src._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/***METHODS***/


/*Helpers*/
bool isLeap(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool isValidYear(int yr)
{
    return (yr <= 2025);
}

bool isValidDay(int day, int yr, int mth)
{
    if (mth == 4 || mth == 6 || mth == 9 || mth == 11)
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

bool isValidMonth(int mth)
{
    return (mth >= 1 && mth <= 12);
}

bool BitcoinExchange::checkDate(std::string line)
{   
    if (line.size() != 10)
        return false;

    if (line.at(4) != '-' || line.at(7) != '-')
        return false;

    size_t firstDash = line.find('-');
    size_t secondDash = line.find('-', firstDash + 1);

    std::string year = line.substr(0, firstDash);
    int yr = toNumConverter<int>(year);

    std::string month = line.substr(firstDash + 1, secondDash - firstDash - 1);
    int mth = toNumConverter<int>(month);

    std::string day = line.substr(secondDash + 1);
    int d = toNumConverter<int>(day);

    return (isValidYear(yr) && isValidMonth(mth) && isValidDay(d, yr, mth));
}

//***HELPER***
void trimInPlace(std::string &str)
{
    // Remove leading spaces
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
    {
        str.clear(); // all spaces
        return;
    }

    // Remove trailing spaces
    size_t end = str.find_last_not_of(" \t\r\n");

    // Erase characters before and after the valid range
    str.erase(end + 1);
    str.erase(0, start);
}

// split data and price and return map container [date]amount
std::map<std::string, std::string> BitcoinExchange::parseInput(std::string line)
{
    std::map<std::string, std::string> res;
    size_t del = line.find('|'); // split 2011-01-03 | 3  to  '2011-01-03' and '3'

    if (del == std::string::npos)
    {
        //std::cout << "Error: wrong format => " << line << std::endl;
        return res; //empty map
    }
    std::string date = line.substr(0, del); // 2011-01-03
    std::string val = line.substr(del + 1); // 3
    trimInPlace(date); //string ok
    trimInPlace(val); //string not ok
    //float v = toNumConverter<float>(val);

    res[date] = val; //string!!!

    return res; //unchecked
}

void BitcoinExchange::searchDb(std::string line) // in this line is date and amount
{

    if (_db.empty())
        std::cerr << "Data base is empty, cant proceed" << std::endl;
    std::map<std::string, std::string> i_line = parseInput(line); //or empty or unverified date and val
    
    
    if (i_line.empty())   // always check!
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }


    std::map<std::string, std::string>::iterator it = i_line.begin();//iterator

    
    std::string date = it->first;   // the KEY

    std::string amount     = it->second;  // the VALUE 
    
    char *endptr;
    float v = static_cast<float>(std::strtod(amount.c_str(), &endptr));

    if (*endptr != '\0') {
        std::cerr << "Error: bad input => " << amount << std::endl;
        return ;
    }
    
    if(!checkDate(date)) {
        std::cerr << "Error: date incorrect => " << date << std::endl;
        return ;
    }
    else if (v < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return ;
    }
    else if (v > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }
    // if _date less than first entry lower_bound points to start
    std::map<std::string, float>::iterator new_it = _db.lower_bound(date);
    // if _date greater than last entry lower_bound returns pointer to past last el.
    if (new_it == _db.end())
    {
        --new_it;
    }
    // if no exact match step back (lower_bound points to first el > date)
    else if (new_it->first != date)
    {
        if (new_it != _db.begin())
            --new_it;
    }
    float price = new_it->second;
    std::cout << std::fixed << std::setprecision(3) << date << " => " << amount << " = " << " [check price: " << price << "] " << price * v << std::endl;
}