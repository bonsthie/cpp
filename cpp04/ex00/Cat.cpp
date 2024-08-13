/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:37:02 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
	LOG("constructor Cat empty")
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
  LOG("constructor Cat copy")
}

Cat::~Cat(void) {
	LOG("destructor Cat")
}

void Cat::makeSound(void) const {
	std::cout << "MEOW MEOW i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
