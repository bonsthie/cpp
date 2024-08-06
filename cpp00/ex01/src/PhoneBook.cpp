/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:56 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 15:20:49 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook(void) : _index(0), _divider(43, '_') {}

bool readInput(std::string &input) {
  std::getline(std::cin, input);
  return std::cin.eof();
}

int PhoneBook::executeCommand(const std::string &command) {
  if (command.compare("ADD") == 0)
    return (ADD());
  else if (command.compare("SEARCH") == 0)
    return (SEARCH());
  else if (command.compare("EXIT") == 0)
    return (EXIT());
  std::cout << "Bad input" << std::endl;
  return (0);
}

int main() {
  PhoneBook phonebook;
  std::string input;

  for (;;) {
    std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
    if (readInput(input))
      break;
    if (phonebook.executeCommand(input))
      break;
  }
}
