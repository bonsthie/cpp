/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:29 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 17:15:55 by babonnet         ###   ########.fr       */
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
    std::cout << "ScavTrap " << _name << ": constructor by copy called"
              << std::endl;
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

void ScavTrap::attack(const std::string &target) {
    if (_health == 0) {
        std::cout << "ScavTrap " << _name
                  << ": can't attack, is dead skull emoji" << std::endl;
    } else if (_energyPoint == 0) {
        std::cout << "ScavTrap " << _name
                  << ": can't attack, no energy points left" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        _energyPoint--;
    }
}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
              << std::endl;
}
