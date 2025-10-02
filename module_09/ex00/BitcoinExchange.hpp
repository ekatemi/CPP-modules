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
    std::map<std::string, std::string> parseInput(std::string line);

public:
    BitcoinExchange();
    BitcoinExchange(std::string file_name);
    BitcoinExchange(const BitcoinExchange &src);

    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    // methods
    void searchDb(std::string line);
};

template <typename T>
T toNumConverter(const std::string &str)
{
    char *end;
    double num = std::strtod(str.c_str(), &end);

    // Check: no number parsed or garbage at the end
    if (end == str.c_str() || *end != '\0')
        return static_cast<T>(-42);

    return static_cast<T>(num);
}

#endif
