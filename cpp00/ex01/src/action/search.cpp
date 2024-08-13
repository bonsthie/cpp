/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:02:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 15:18:52 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>

static std::string shorten(std::string str) {
    if (str.length() <= COLUMN_SIZE)
        return (str);
    return (str.substr(0, COLUMN_SIZE - 1) + ".");
}

static void printContact(Contact Contact, int index) {
    std::cout << std::setw(COLUMN_SIZE) << index << "|" << std::setw(COLUMN_SIZE)
              << shorten(Contact.getFirstName()) << "|" << std::setw(COLUMN_SIZE)
              << shorten(Contact.getLastName()) << "|" << std::setw(COLUMN_SIZE)
              << shorten(Contact.getNickname()) << std::endl;
}

static void displayTable(Contact *Contact, std::string _divider) {

    std::cout << _divider << std::endl;
    std::cout << "  INDEX   |FIRST NAME|LAST  NAME| NICKNAME " << std::endl;
    std::cout << _divider << std::endl;
    for (int i = 0; i < 8 && !Contact[i].getFirstName().empty(); i++) {
        printContact(Contact[i], i + 1);
    }
    std::cout << _divider << std::endl;
}

static void printInfo(Contact Contact) {
    std::cout << std::setw(16) << "FIRST NAME: " << Contact.getFirstName() << std::endl
              << std::setw(16) << "LAST NAME: " << Contact.getLastName() << std::endl
              << std::setw(16) << "NICKNAME: " << Contact.getNickname() << std::endl
              << std::setw(16) << "PHONE NUMBER: " << Contact.getPhoneNumber() << std::endl
              << std::setw(16) << "DARKEST SECRET: " << Contact.getDarkestSecret() << std::endl;
}

static int fill_number(const char *str) {
    char    *endptr;
    long int i;

    if (!str)
        return (-1);
    while (*str && isspace(*str))
        str++;
    if (!*str)
        return (-1);
    i = strtol((char *)str, &endptr, 10);
    if ((*endptr && !isdigit(*endptr) && !isspace(*endptr)) || i < 0 || i > INT_MAX)
        return (-1);
    if (endptr - str > 11)
        return (-1);
    while (*endptr && isspace(*endptr))
        endptr++;
    if (*endptr)
        return (-1);
    return (i);
}

int PhoneBook::SEARCH(void) {
    std::string str;

    if (_contact[0].getFirstName().empty()) {
        std::cout << "No Contacts" << std::endl;
        return (0);
    }

    displayTable(_contact, _divider);
    std::cout << "Enter un index: ";
    if (readInput(str))
		return (1);
    int index = fill_number(str.c_str()) - 1;
    if (index >= 8 || index < 0)
        std::cout << "this index " << index + 1 << " is out of scop" << std::endl;
    else if (_contact[index].getFirstName().empty())
        std::cout << "this Contact dosen't exist" << std::endl;
    else
        printInfo(_contact[index]);
    std::cout << _divider << std::endl;
	return (0);
}
