/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:01:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 15:19:04 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

// need to check input
int PhoneBook::ADD(void) {
  std::string input;

  std::cout << "New Contact creation" << std::endl;

  std::cout << "NAME: ";
  if (readInput(input)) return (1);
  _contact[_index].setFirstName(input);

  std::cout << "LAST NAME: ";
  if (readInput(input)) return (1);
  _contact[_index].setLastName(input);

  std::cout << "NICKNAME: ";
  if (readInput(input)) return (1);
  _contact[_index].setNickname(input);

  std::cout << "PHONE NUMBER: ";
  if (readInput(input)) return (1);
  _contact[_index].setPhoneNumber(input);

  std::cout << "DARKEST SECRET: ";
  if (readInput(input)) return (1);
  _contact[_index].setDarkestSecret(input);
  _index++;
  
  return (0);
}
