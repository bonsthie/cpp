/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 10:01:55 by bonsthie         ###   ########.fr       */
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

void Dog::makeSound(void) const {
  std::cout << "OuAf OuAf i'm the dog" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain = src._brain;
  return (*this);
}
