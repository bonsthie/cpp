/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:50 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:07:10 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat") {
  if (this != &src)
    *this = src;
}

WrongCat::~WrongCat(void) {}

void WrongCat::makeSound(void) const {
	std::cout << "MEOW MEOW JE SUIS LE CHAT" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
