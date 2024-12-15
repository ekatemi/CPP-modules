#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

void Account::_displayTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    
    std::cout << "[" 
              << std::setfill('0')
              << std::setw(4) << (localTime->tm_year + 1900)
              << std::setw(2) << (localTime->tm_mon + 1)
              << std::setw(2) << localTime->tm_mday
              << "_"
              << std::setw(2) << localTime->tm_hour
              << std::setw(2) << localTime->tm_min
              << std::setw(2) << localTime->tm_sec
              << "] ";
}


void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" 
        << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << _amount;
    
    if (withdrawal > _amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    _amount -= withdrawal;
    _nbWithdrawals++;
    
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return true;
}
	int		Account::checkAmount( void ) const
    {
        return _amount;
    }
    //[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
	void	Account::displayStatus( void ) const
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount 
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    }

    // Constructor
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

// Destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
}