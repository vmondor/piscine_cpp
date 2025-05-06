#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account()
{
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    return ;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
    return ;
}

void    Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if (this->_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (0);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (1);
}

int Account::checkAmount() const
{
    return this->_amount;
}

void    Account::displayStatus() const
{
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
    return ;
}

void    Account::_displayTimestamp()
{
    std::time_t current = std::time(0);
    std::tm *time = std::localtime(&current);
    std::cout << "[" << 1900 + time->tm_year << std::setw(2) << std::setfill('0') << 1 + time->tm_mon << std::setw(2) << std::setfill('0') << time->tm_mon << "_"
            << std::setw(2) << std::setfill('0') << time->tm_hour << std::setw(2) << std::setfill('0') << time->tm_min << std::setw(2) << std::setfill('0') << time->tm_sec << "]";
    return ;
}