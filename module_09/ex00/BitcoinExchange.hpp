#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> db; //i store db here
        float val; //value
    
public:
    BitcoinExchange();
    //BitcoinExchange(???);
    BitcoinExchange(const BitcoinExchange &src);

    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    //methods
    //should output 
    
};

#endif
