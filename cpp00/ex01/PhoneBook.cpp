/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 18:10:05 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cstdlib>
#include <iostream>

PhoneBook::PhoneBook(void) : _divider(43, '_'), _index(0) {}

// need to do check;
std::string readInput() {
    std::string str;

    std::getline(std::cin, str);
    if (std::cin.eof())
        exit(0);
    /* if (str.empty()) */
    /* 	return (NULL); */
    return (str);
}

void PhoneBook::executeCommand(const std::string &command) {
    if (command.compare("ADD") == 0)
        ADD();
    else if (command.compare("SEARCH") == 0)
        SEARCH();
    else if (command.compare("EXIT") == 0)
        EXIT();
    else
        std::cout << "Bad input" << std::endl;
}

int main() {
    PhoneBook   phonebook;
    std::string input;

    for (;;) {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
        input = readInput();
        phonebook.executeCommand(input);
    }
}
