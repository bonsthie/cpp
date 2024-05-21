/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:29 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 14:24:25 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << ": constructor called" << std::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap " << _name << ": constructor by copy called" << std::endl;
}

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap no name: constructor void called" << std::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
              << std::endl;
}
