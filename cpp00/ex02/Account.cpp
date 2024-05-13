/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:28:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/13 23:52:07 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

/* utils Account class function  */

void log(const char *name, int value) { std::cout << name << ":" << value; }

void log(const char *name, int value, const char *name2) {
    std::cout << name << ":" << value << ";" << name2;
}

void log(const char *name1, int value1, const char *name2, int value2) {
    std::cout << name1 << ":" << value1 << ";";
    log(name2, value2);
}

void log(const char *name1, int value1, const char *name2, int value2,
         const char *name3) {
    std::cout << name1 << ":" << value1 << ";";
    log(name2, value2, name3);
}

void log(const char *name1, int value1, const char *name2, int value2,
         const char *name3, int value3) {
    std::cout << name1 << ":" << value1 << ";";
    log(name2, value2, name3, value3);
}

void log(const char *name1, int value1, const char *name2, int value2,
         const char *name3, int value3, const char *name4, int value4) {
    std::cout << name1 << ":" << value1 << ";";
    log(name2, value2, name3, value3, name4, value4);
}

void log(const char *name1, int value1, const char *name2, int value2,
         const char *name3, int value3, const char *name4, int value4,
         const char *name5, int value5) {
    std::cout << name1 << ":" << value1 << ";";
    log(name2, value2, name3, value3, name4, value4, name5, value5);
}

#define LOG(...)                                                               \
    {                                                                          \
        _displayTimestamp();                                                   \
        log(__VA_ARGS__);                                                      \
        std::cout << std::endl;                                                \
    }

/* Account classs function */

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
    LOG("account", _nbAccounts, "total", _totalAmount, "deposits",
        _totalNbDeposits, "withdrawal", _totalNbWithdrawals);
}

void Account::displayStatus(void) const {
    LOG("index", _accountIndex, "amount", _amount, "deposits", _nbDeposits,
        "withdrawal", _nbWithdrawals);
}

void Account::makeDeposit(int deposit) {
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    LOG("index", _accountIndex, "p_amount", _amount - deposit, "deposit",
        deposit, "amount", _amount, "nb_deposit", _nbDeposits);
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > _amount) {
        LOG("index", _accountIndex, "p_amount", _amount, "withdrawal:refused");
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    LOG("index", _accountIndex, "p_amount", _amount + withdrawal, "amount",
        _amount, "nb_withdrawals", _nbWithdrawals);
    return (true);
}

void Account::_displayTimestamp() {
    time_t timeStamp;

    time(&timeStamp);
    std::cout << "[" << timeStamp << "] ";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    LOG("index", _accountIndex, "amount", _amount, "created")
}

Account::~Account() {
    LOG("index", _accountIndex, "amount", _amount, "closed");
}
