/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:02:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 18:11:03 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.h"
#include <iomanip>
#include <iostream>

static std::string shorten(std::string str) {
    if (str.length() <= COLUMN_SIZE)
        return (str);
    return (str.substr(0, COLUMN_SIZE - 1) + ".");
}

static void printContact(contact contact, int index) {
    std::cout << std::setw(COLUMN_SIZE) << index << "|" << std::setw(COLUMN_SIZE)
              << shorten(contact.getFirstName()) << "|" << std::setw(COLUMN_SIZE)
              << shorten(contact.getLastName()) << "|" << std::setw(COLUMN_SIZE)
              << shorten(contact.getNickname()) << std::endl;
}

static void displayTable(contact *contact, std::string _divider) {

    std::cout << _divider << std::endl;
    std::cout << "  INDEX   |FIRST NAME|LAST  NAME| NICKNAME " << std::endl;
    std::cout << _divider << std::endl;
    for (int i = 0; i < 8 && !contact[i].getFirstName().empty(); i++)
        printContact(contact[i], i + 1);
    std::cout << _divider << std::endl;
}

static void printInfo(contact contact) {
    std::cout << std::setw(16) << "FIRST NAME: " << contact.getFirstName() << std::endl
              << std::setw(16) << "LAST NAME: " << contact.getLastName() << std::endl
              << std::setw(16) << "NICKNAME: " << contact.getNickname() << std::endl
              << std::setw(16) << "PHONE NUMBER: " << contact.getPhoneNumber() << std::endl
              << std::setw(16) << "DARKEST SECRET: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::SEARCH(void) {
    std::string str;

    if (_contact[0].getFirstName().empty()) {
        std::cout << "No contacts" << std::endl;
        return;
    }
    displayTable(_contact, _divider);
    std::cout << "Enter un index: ";
    str = readInput();
    // verify input but for now les croisés
    int index = std::atoi(str.c_str()) - 1;
    if (index >= 8 || index < 0)
        std::cout << "this index " << index + 1 << " is out of scop" << std::endl;
    else if (_contact[index].getFirstName().empty())
        std::cout << "this contact dosen't exist" << std::endl;
    else
        printInfo(_contact[index]);
    std::cout << _divider << std::endl;
}
