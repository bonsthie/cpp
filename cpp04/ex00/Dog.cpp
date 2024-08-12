/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:06:33 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog(void) : Animal("Dog") {}

Dog::Dog(const Dog &src) : Animal("Dog") {
  if (this != &src)
    *this = src;
}

Dog::~Dog(void) {}

void Dog::makeSound(void) const {
	std::cout << "OuAf OuAf JE SUIS LE CHIENG" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
