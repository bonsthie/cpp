/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 12:03:38 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  LOG("constructor Dog empty")
  _brain = new Brain;
}

Dog::Dog(const Dog &src) : Animal("Dog") {
	LOG("constructor Dog copy")
  if (this != &src)
    *this = src;
  _brain = new Brain;
}

Dog::~Dog(void) {
  LOG("destructor Dog")
  delete _brain;
}

void Dog::setBrainIdear(const std::string &idea, uint8_t offset) {
  if (offset >= 100)
    return;
  _brain->ideas[offset] = idea;
}

std::string Dog::getBrainIdear(uint8_t offset) {
  if (offset < 100)
    return _brain->ideas[offset];
  return "";
}

void Dog::makeSound(void) const {
  std::cout << "OuAf OuAf i'm the dog" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
