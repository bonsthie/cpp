/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:28:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/07 17:03:47 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <cstdarg>
#include <ctime>
#include <iostream>

/* utils Account class function  */

void __log(int count, ...) {
    va_list args;
    va_start(args, count);

    for (; count > 1; count -= 2) {
        const char *str = va_arg(args, const char *);
        int         value = va_arg(args, int);
        std::cout << str << ":" << value;
        if (count > 2)
            std::cout << ";";
    }
    if (count == 1) {
        const char *str = va_arg(args, const char *);
        std::cout << str;
    }
    va_end(args);
}

#define LOG(count, ...)                                                                            \
    {                                                                                              \
        _displayTimestamp();                                                                       \
        __log(count, __VA_ARGS__);                                                                 \
        std::cout << std::endl;                                                                    \
    }

/* Account class function */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }
int Account::checkAmount(void) const { return (_amount); }

void Account::displayAccountsInfos(void) {
    LOG(8, "accounts", _nbAccounts, "total", _totalAmount, "deposits", _totalNbDeposits,
        "withdrawals", _totalNbWithdrawals);
}

void Account::displayStatus(void) const {
    LOG(8, "index", _accountIndex, "amount", _amount, "deposits", _nbDeposits, "withdrawals",
        _nbWithdrawals);
}

void Account::makeDeposit(int deposit) {
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    LOG(10, "index", _accountIndex, "p_amount", _amount - deposit, "deposit", deposit, "amount",
        _amount, "nb_deposits", _nbDeposits);
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > _amount) {
        LOG(5, "index", _accountIndex, "p_amount", _amount, "withdrawal:refused");
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    LOG(10, "index", _accountIndex, "p_amount", _amount + withdrawal, "withdrawal", withdrawal, "amount", _amount,
        "nb_withdrawals", _nbWithdrawals);
    return (true);
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char buffer	[30];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,30,"[%Y%m%d_%H%M%S] ",timeinfo);
	std::cout << buffer; 
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    LOG(5, "index", _accountIndex, "amount", _amount, "created")
}

Account::~Account() { LOG(5, "index", _accountIndex, "amount", _amount, "closed"); }
