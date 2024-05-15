/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/16 00:14:21 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook(void) : _index(0), _divider(43, '_') {}

bool readInput(std::string &input) {
    std::getline(std::cin, input);
    return !std::cin.eof();
}

int PhoneBook::executeCommand(const std::string &command) {
    if (command.compare("ADD") == 0)
        ADD();
    else if (command.compare("SEARCH") == 0)
        SEARCH();
    else if (command.compare("EXIT") == 0) {
        EXIT();
        return (1);
    } else
        std::cout << "Bad input" << std::endl;
    return (0);
}

int main() {
    PhoneBook   phonebook;
    std::string input;

    for (;;) {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
        if (readInput(input))
            break;
        if (phonebook.executeCommand(input))
            break;
    }
}
