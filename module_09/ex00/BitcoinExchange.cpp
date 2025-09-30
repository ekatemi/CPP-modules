#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : db(0) { }
BitcoinExchange::BitcoinExchange(std::string &db) : {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _date(src._date), _amount(src._amount) {
    if (db.empty())
    {
        throw std::runtime_error("Data base is empty");
    
    }
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
    {
        _date = src._date;
        _amount = src._amount;
        _db = src._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/***METHODS***/

void BitcoinExchange::setVal(float num) {
    if (num < 0)
    {
        std::cout << "Error: amount cant be negative => " << num << std::endl;
        _amount = -42;
        return ;
    }
        
    else if (num > 1000) {
        std::cout << "Error: amount cant be more than 1000." << std::endl;
        _amount = -42;
        return ;
    }
    _amount = num;
}

/*Helpers*/
bool isLeap(int year)
{
    return (((year % 4 == 0) && 
             (year % 100 != 0)) ||
             (year % 400 == 0));
}

bool isValidYear(int yr) {
    return ( yr <= 2025);
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


bool checkDate(std::string line)
{
    if(line.size() != 10)
        return false;
    
    if (line.at(4) != '-' || line.at(7) != '-')
        return false;
    
    size_t firstDash = line.find('-');
    size_t secondDash = line.find('-', firstDash + 1);

    std::string year  = line.substr(0, firstDash);
    int yr = toNumConverter<int>(year);
    
    std::string month = line.substr(firstDash + 1, secondDash - firstDash - 1);
    int mth = toNumConverter<int>(month);

    std::string day = line.substr(secondDash + 1);
    int d = toNumConverter<int>(day);
    
    return (isValidYear(yr) && isValidMonth(mth) && isValidDay(d, yr, mth));
}

void BitcoinExchange::setDate(std::string date) {
    _date = date;
}

bool BitcoinExchange::searchDb(std::map<std::string, float> db) {
    
    if(_date.empty() || _amount < 0)
        return false;
    if (db.empty())
    {
        std::cerr << "Data base is empty" << std::endl;
        return false; 
    }

    //if _date less than first entry lower_bound points to start
    std::map<std::string,float>::iterator it = db.lower_bound(_date);
    //if _date greater than last entry lower_bound returns pointer to past last el.
    if (it == db.end()){
        --it;
    }     
    //if no exact match step back (lower_bound points to first el > date)
    else if (it->first != _date) {
        if (it != db.begin())
            --it;
    }
    float price = it->second;
    std::cout << std::fixed << std::setprecision(3) << _date << " => " << _amount << " = " << " [check price: " << price << "] " << price * _amount << std::endl;
    return true;
}