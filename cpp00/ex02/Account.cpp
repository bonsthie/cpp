/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:28:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 21:24:01 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

#define PRINT_VARIABLE(arg, truncate) (char *)(#arg) + truncate << ":" << arg
#define PRINT_VALUE(name, value) name << ":" << value

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }
int Account::checkAmount(void) const { return (_amount); }

static void printStartPrompt(int index, int amount) {
    std::cout << PRINT_VARIABLE(index, 0) << ";" << PRINT_VARIABLE(amount, 0)
              << ";";
}

static void printStartPromptTransaction(int index, int p_amount) {
    std::cout << PRINT_VARIABLE(index, 0) << ";" << PRINT_VARIABLE(p_amount, 0)
              << ";";
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << PRINT_VALUE("accounts", _nbAccounts) << ";"
              << PRINT_VALUE("total", _totalAmount) << ";"
              << PRINT_VALUE("deposits", _totalNbDeposits) << ";"
              << PRINT_VALUE("withdrawals", _totalNbWithdrawals) << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    printStartPrompt(_accountIndex, _amount);
    std::cout << PRINT_VALUE("deposits", _nbDeposits) << ";"
              << PRINT_VALUE("withdrawals", _nbWithdrawals) << std::endl;
}

void Account::_displayTimestamp() {
    time_t timeStamp;

    time(&timeStamp);
    std::cout << "[" << timeStamp << "] ";
}

void Account::makeDeposit(int deposit) {
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    printStartPromptTransaction(_accountIndex, _amount);
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << PRINT_VARIABLE(deposit, 0) << ";" << PRINT_VARIABLE(_amount, 1)
              << ";" << PRINT_VALUE("nb_deposit", _nbDeposits) << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    printStartPromptTransaction(_accountIndex, _amount);
    if (withdrawal > _amount) {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << PRINT_VARIABLE(withdrawal, 0) << ";"
              << PRINT_VARIABLE(_amount, 1) << ";"
              << PRINT_VALUE("nb_withdrawls", _nbWithdrawals) << std::endl;
    return (true);
}

Account::Account(int initial_deposit)
    : _nbDeposits(0),
      _nbWithdrawals(0),
      _accountIndex(_nbAccounts),
      _amount(initial_deposit) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    printStartPrompt(_accountIndex, _amount);
    std::cout << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    printStartPrompt(_accountIndex, _amount);
    std::cout << "closed" << std::endl;
}

int main() {
    Account test(10);
    Account test1(20);
    Account test2(30);
    test.displayAccountsInfos();
    test.makeDeposit(100);
    test.makeWithdrawal(50);
    test1.makeWithdrawal(50);
    test.displayStatus();
    test.displayAccountsInfos();
    test.getTotalAmount();
    return 1;
}
