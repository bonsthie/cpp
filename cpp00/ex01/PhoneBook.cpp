/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/11 20:47:53 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>


PhoneBook::PhoneBook(void) {
  _index = 0;
}

// need to do check;
void PhoneBook::ADD(void) { 
	std::string input;

	std::cout << "New contact creation" << std::endl;
	std::cout << "NAME: ";
	std::cin >> input;
	_contact[_index].setFirstName(input);
	std::cout << "LAST NAME: ";
	std::cin >> input;
	_contact[_index].setLastName(input);
	std::cout << "NICKNAME: ";
	std::cin >> input;
	_contact[_index].setNickname(input);
	std::cout << "PHONE NUMBER: ";
	std::cin >> input;
	_contact[_index].setPhoneNumber(input);
	std::cout << "DARKEST SECRET: ";
	std::cin >> input;
	_contact[_index].setDarkestSecret(input);
	_index++;
}

static std::string shorten(std::string str){
	if (str.length() <= COLONNE_SIZE)
		return (str);
	return (str.substr(0, COLONNE_SIZE - 1) + ".");
}

static void printContact(contact contact, int index) {
	std::cout  << std::setw(COLONNE_SIZE) << index <<  "|" 
		<< std::setw(COLONNE_SIZE) << shorten(contact.getFirstName()) << "|" 
		<< std::setw(COLONNE_SIZE) << shorten(contact.getLastName()) << "|" 
		<< std::setw(COLONNE_SIZE) << shorten(contact.getNickname()) << std::endl;
}

static void displayTable(contact *contact) {
	static const std::string divider(43, '_');

	std::cout << divider << std::endl; 
	std::cout << "  INDEX  |FIRST NAME|LAST  NAME| NICKNAME " << std::endl;
	std::cout << divider << std::endl; 
	for (int i = 0; i < 8 && !contact[i].getFirstName().empty(); i++)
		printContact(contact[i], i + 1);
	std::cout << divider << std::endl; 
}

static void printInfo(contact contact)
{
	std::cout << std::setw(16) << "FIRST NAME: " << contact.getFirstName() << std::endl 
	 << std::setw(16) << "LAST NAME: " << contact.getLastName() << std::endl 
	 << std::setw(16) << "NICKNAME: " << contact.getNickname() << std::endl 
	 << std::setw(16) << "PHONE NUMBER" << contact.getPhoneNumber() << std::endl 
	 << std::setw(16) << "DARKEST SECRET: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::SEARCH(void) {
	std::string str;

	if (_contact[0].getFirstName().empty()) {
		std::cout << "No contacts" << std::endl;
		return;
	}
	displayTable(_contact);
	std::getline(std::cin, str);
	int index = std::atoi(str.c_str()) - 1;
	if (index >= 8 || index <= 0)
		std::cout << "this index " << index + 1 << " is out of scop" << std::endl;
	else if (_contact[index].getFirstName().empty())
		std::cout << "this contact dosen't exist" << std::endl;
	else 
		printInfo(_contact[index]);
}

void PhoneBook::EXIT(void) { 
	exit(0);
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
  PhoneBook phonebook;
  std::string input;

  for (;;) {
    std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
    std::cin >> input;
	phonebook.executeCommand(input);
  }
}
