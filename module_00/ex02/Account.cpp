#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
    return _totalAmount;
}
int	Account::getNbDeposits( void ) {
    return  _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit ) {
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;  
}

bool	Account::makeWithdrawal( int withdrawal ) {
    if (withdrawal > _amount) {
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    return true;
}

int		Account::checkAmount( void ) const {
    return _amount;
}

void Account::_displayTimestamp (void) {
    // Get the current time
    std::time_t now = std::time(nullptr);
    //std::tm* localTime = std::localtime(&now);

    // Format and display the timestamp
    std::cout << '['
              << now
              << "] ";
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::displayAccountsInfos(void) {
    // Display total accounts and total amounts
    _displayTimestamp();  // Optional: if you want to log the time of this display
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts; // Set the account index to the current number of accounts
    _nbAccounts++;                // Increment the account count
    _totalAmount += initial_deposit; // Update the total amount
    _displayTimestamp();          // Optional: Display the timestamp when the account is created
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor implementation
Account::~Account(void) {
    _nbAccounts--;                // Decrement the account count
    _totalAmount -= _amount;      // Update the total amount
    _displayTimestamp();          // Optional: Display the timestamp when the account is destroyed
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";destroyed" << std::endl;
}