/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:24 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:35:23 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string &type) : _type(type){
	LOG("constructor Animal string")
}
Animal::Animal(void) : _type("Animal") {
	LOG("constructor Animal empty")
}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
  LOG("constructor Animal copy")
}

Animal::~Animal(void) {
	LOG("destructor Animal empty")
}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
