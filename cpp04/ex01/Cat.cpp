/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 12:03:35 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  LOG("constructor Cat empty")
  _brain = new Brain;
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  LOG("constructor Cat copy")
  if (this != &src)
    *this = src;
  _brain = new Brain;
}

Cat::~Cat(void) {
  LOG("destructor Cat")
  delete _brain;
}

void Cat::setBrainIdear(const std::string &idea, uint8_t offset) {
  if (offset >= 100)
    return;
  _brain->ideas[offset] = idea;
}

std::string Cat::getBrainIdear(uint8_t offset) {
  if (offset < 100)
    return _brain->ideas[offset];
  return "";
}

void Cat::makeSound(void) const {
  std::cout << "MEOW MEOW i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
