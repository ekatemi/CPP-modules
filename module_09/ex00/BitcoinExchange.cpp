#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string date, float amount) : _date(date), _amount(amount) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange &src) : db(src.db), _date(src._date), _amount(src._amount) {}

// BitcoinExchange &operator=(const BitcoinExchange &src);
//     ~BitcoinExchange();

//     //methods
//     void setVal(float num);
//     void setDate(std::string date);


//     void printRes();
