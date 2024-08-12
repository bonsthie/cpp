/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:15:24 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 19:57:11 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string &type) : _type(type) {}

Animal::Animal(void) : _type("Animal") {}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
}

Animal::~Animal(void) {}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
