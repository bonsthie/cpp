/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:24 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/14 12:40:18 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.h"
#include <iostream>

AAnimal::AAnimal(const std::string &type) : _type(type){
	LOG("constructor AAnimal string")
}
AAnimal::AAnimal(void) : _type("AAnimal") {
	LOG("constructor AAnimal empty")
}

AAnimal::AAnimal(const AAnimal &src) {
  if (this != &src)
    *this = src;
  LOG("constructor AAnimal copy")
}

AAnimal::~AAnimal(void) {
	LOG("destructor AAnimal empty")
}

const std::string &AAnimal::getType(void) const { return _type; }

void AAnimal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
