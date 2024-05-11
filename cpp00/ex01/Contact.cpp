/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:49:41 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/11 15:37:20 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

std::string contact::getFirstName(void) { return (_firstName); }

std::string contact::getLastName(void) { return (_lastName); }

std::string contact::getNickname(void) { return (_nickname); }

std::string contact::getPhoneNumber(void) { return (_phoneNumber); }

std::string contact::getDarkestSecret(void) { return (_darkestSecret); }

void contact::setFirstName(std::string newFirstName) { _firstName = newFirstName; }

void contact::setLastName(std::string newLastName) { _lastName = newLastName; }

void contact::setNickname(std::string newNickname) { _nickname = newNickname; }

void contact::setPhoneNumber(std::string newPhoneNumber) { _phoneNumber = newPhoneNumber; }

void contact::setDarkestSecret(std::string newDarkestSecret) { _darkestSecret = newDarkestSecret; }
