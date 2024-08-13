/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:36:49 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
	LOG("constructor Dog empty")
}

Dog::Dog(const Dog &src) : Animal("Dog") {
  if (this != &src)
    *this = src;
  LOG("constructor Dog copy")
}

Dog::~Dog(void) {
	LOG("destructor Dog")
}

void Dog::makeSound(void) const {
	std::cout << "OuAf OuAf i'm the dog" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
