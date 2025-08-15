#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> db; //store db here
        std::string _date; 
        float _amount; //value
    
public:
    BitcoinExchange(std::string date, float amount);
    BitcoinExchange(const BitcoinExchange &src);

    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    //methods
    void setVal(float num);
    void setDate(std::string date);


    void printRes();
    
};

#endif
