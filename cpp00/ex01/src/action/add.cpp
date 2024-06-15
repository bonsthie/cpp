/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:01:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/06/15 23:19:29 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

// need to check input
void PhoneBook::ADD(void) {
    std::string input;

    std::cout << "New Contact creation" << std::endl;
    std::cout << "NAME: ";
    readInput(input);
    _contact[_index].setFirstName(input);
    std::cout << "LAST NAME: ";
    readInput(input);
    _contact[_index].setLastName(input);
    std::cout << "NICKNAME: ";
    readInput(input);
    readInput(input);
    _contact[_index].setNickname(input);
    std::cout << "PHONE NUMBER: ";
    readInput(input);
    _contact[_index].setPhoneNumber(input);
    std::cout << "DARKEST SECRET: ";
    readInput(input);
    _contact[_index].setDarkestSecret(input);
    _index++;
}
