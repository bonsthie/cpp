/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:24 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:07:49 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  if (this != &src)
    *this = src;
}

WrongAnimal::~WrongAnimal(void) {}

const std::string &WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "chuterstock animal from Wrong Animal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
