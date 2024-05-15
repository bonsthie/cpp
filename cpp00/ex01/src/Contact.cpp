/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:49:41 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/14 00:34:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

std::string Contact::getFirstName(void) const { return (_firstName); }

std::string Contact::getLastName(void) const { return (_lastName); }

std::string Contact::getNickname(void) const { return (_nickname); }

std::string Contact::getPhoneNumber(void) const { return (_phoneNumber); }

std::string Contact::getDarkestSecret(void) const { return (_darkestSecret); }

void Contact::setFirstName(std::string newFirstName) { _firstName = newFirstName; }

void Contact::setLastName(std::string newLastName) { _lastName = newLastName; }

void Contact::setNickname(std::string newNickname) { _nickname = newNickname; }

void Contact::setPhoneNumber(std::string newPhoneNumber) { _phoneNumber = newPhoneNumber; }

void Contact::setDarkestSecret(std::string newDarkestSecret) { _darkestSecret = newDarkestSecret; }
