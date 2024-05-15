/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 23:18:08 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cstdlib>
#include <iostream>

PhoneBook::PhoneBook(void) : _index(0), _divider(43, '_') {}

std::string readInput() {
    std::string str;

    std::getline(std::cin, str);
    if (std::cin.eof())
        std::exit(0);
    return (str);
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
        input = readInput();
        if (phonebook.executeCommand(input))
			break;
    }
}
