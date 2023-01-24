/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:24:52 by yje               #+#    #+#             */
/*   Updated: 2023/01/24 23:14:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int amount)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
	  _nbWithdrawals = 0;
    _amount = amount;
    _totalAmount = amount + _totalAmount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int	Account::getNbAccounts(void)
{
    return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t	ts;
    char buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout <<" accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
   std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}

void Account::makeDeposit(int deposit)
{
    _amount = _amount + deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;
    _totalAmount = _totalAmount + deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit \
    << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits<< std::endl; 
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount - withdrawal < 0)
    {
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl; 
        return false;
    }
    else
    {
        ++_nbWithdrawals;
        ++_totalNbWithdrawals;
        _amount = _amount - withdrawal;
        _totalAmount = _totalAmount - withdrawal;
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal <<  ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true; 
    }
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}