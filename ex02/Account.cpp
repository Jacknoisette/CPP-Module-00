/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:24:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 17:29:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>
#include <fstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
std::ofstream fd("account.log", std::ios::trunc);

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << " index:" << _accountIndex;
	fd << ";amount:" << _amount;
	fd << ";created" << std::endl;
	fd.close();
}

Account::~Account(void)
{
	_nbAccounts--;
    _totalAmount -= _amount;

	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << " index:" << _accountIndex;
	fd << ";amount:" << _amount;
	fd << ";closed" << std::endl;
	fd.close();
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm* timeInfo = std::localtime(&t);

	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << "[" << (1900 + timeInfo->tm_year);
	if ((1 + timeInfo->tm_mon) < 10)
		fd << "0";
	fd << (1 + timeInfo->tm_mon);
	fd << timeInfo->tm_mday << "_" ;
	fd << timeInfo->tm_hour;
	fd << timeInfo->tm_min;
	fd << timeInfo->tm_sec << "]";
	fd.close();
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << " accounts:" << getNbAccounts();
	fd << ";total:" << getTotalAmount();
	fd << ";deposits:" << getNbDeposits();
	fd << ";withdrawals:" << getNbWithdrawals();
	fd << std::endl;
	fd.close();
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << " index:" << _accountIndex;
	fd << ";p_amount:" << checkAmount();
	fd << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	fd << ";amount:" << _amount;
	fd << ";nb_deposits:" << _nbDeposits;
	fd << std::endl;
	fd.close();
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return false;
	fd << " index:" << _accountIndex;
	fd << ";p_amount:" << checkAmount();
	if (_amount < withdrawal)
	{		
        fd << ";withdrawal:refused";
		fd << std::endl;
		fd.close();
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	fd << ";withdrawal:" << withdrawal;
	fd << ";amount:" << checkAmount();
	fd << ";nb_withdrawals:" << _nbWithdrawals;
	fd << std::endl;
	fd.close();
	return (true);
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::ofstream fd("account.log", std::ios::app);
	if (!fd)
		return ;
	fd << " index:" << _accountIndex;
	fd << ";amount:" << checkAmount();
	fd << ";deposits:" << _nbDeposits;
	fd << ";withdrawals:" << _nbWithdrawals;
	fd << std::endl;
	fd.close();
}