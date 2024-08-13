/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:24 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:34:36 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	LOG("WrongAnimal constructor string")
}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	LOG("WrongAnimal constructor empty")
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  if (this != &src)
    *this = src;
  LOG("WrongAnimal constructor copy")
}

WrongAnimal::~WrongAnimal(void) {
  LOG("WrongAnimal destructor")
}

const std::string &WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "chuterstock animal from Wrong Animal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
