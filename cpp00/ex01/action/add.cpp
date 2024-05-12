/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:01:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 18:10:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.h"
#include <iostream>

// need to check input
void PhoneBook::ADD(void) {
    std::string input;

    std::cout << "New contact creation" << std::endl;
    std::cout << "NAME: ";
    input = readInput();
    _contact[_index].setFirstName(input);
    std::cout << "LAST NAME: ";
    input = readInput();
    _contact[_index].setLastName(input);
    std::cout << "NICKNAME: ";
    input = readInput();
    _contact[_index].setNickname(input);
    std::cout << "PHONE NUMBER: ";
    input = readInput();
    _contact[_index].setPhoneNumber(input);
    std::cout << "DARKEST SECRET: ";
    input = readInput();
    _contact[_index].setDarkestSecret(input);
    _index++;
}
