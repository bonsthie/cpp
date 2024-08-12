/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:06:53 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
}

Cat::~Cat(void) {}

void Cat::makeSound(void) const {
	std::cout << "MEOW MEOW JE SUIS LE CHAT" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
