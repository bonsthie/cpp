/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 10:02:05 by bonsthie         ###   ########.fr       */
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

void Cat::makeSound(void) const {
  std::cout << "MEOW MEOW i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain = src._brain;
  return (*this);
}
