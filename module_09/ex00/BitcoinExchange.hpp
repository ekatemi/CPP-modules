#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>

class BitcoinExchange {
    private:
        //const std::map<std::string, float> db; //store db here
        std::string _date; 
        float _amount; //value
    
public:
    BitcoinExchange();
    BitcoinExchange(std::string date, float amount);
    BitcoinExchange(const BitcoinExchange &src);

    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    //methods
    void setVal(float num);
    void setDate(std::string date);
    bool searchDb(std::map<std::string, float> db);
    
};

template <typename T>
T toNumConverter(const std::string &str) {
    char *end;
    double num = std::strtod(str.c_str(), &end);
    if (end == str.c_str() || *end != '\0')
        return static_cast<T>(-3);
    return static_cast<T>(num);
}


#endif
