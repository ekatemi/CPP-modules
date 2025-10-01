#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>
#include <iomanip>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::map<std::string, float> _db; // store db here
    // std::string _date;
    // float _amount; // value
    bool checkDate(std::string line);

public:
    BitcoinExchange();
    BitcoinExchange(std::string &file_name);
    BitcoinExchange(const BitcoinExchange &src);

    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    // methods
    void setVal(float num);
    void setDate(std::string date);
    bool searchDb(std::map<std::string, float> db);
};

template <typename T>
T toNumConverter(const std::string &str)
{
    char *end;
    double num = std::strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\0')
        return static_cast<T>(-3);
    return static_cast<T>(num);
}

#endif
