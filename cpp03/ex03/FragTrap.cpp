/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:29 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 18:56:17 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << ": constructor called" << std::endl;
    _health = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << _name << ": constructor by copy called"
              << std::endl;
}

FragTrap::FragTrap(void) {
    std::cout << "FragTrap no name: constructor void called" << std::endl;
    _health = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << ": high fives request" << std::endl;
}
