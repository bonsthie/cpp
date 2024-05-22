/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:33:19 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 14:25:25 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>
#include <ostream>

ClapTrap::ClapTrap(const std::string &name)
    : _name(name),
      _energyPoint(10),
      _attackDamage(0),
      _health(10) {
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap " << _name << " constructor by copy called" << std::endl;
}

ClapTrap::ClapTrap(void) : _energyPoint(10), _attackDamage(0), _health(10) {
    std::cout << "ClapTrap no name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_health == 0) {
        std::cout << "ClapTrap " << _name
                  << ": can't attack, is dead skull emoji" << std::endl;
    } else if (_energyPoint == 0) {
        std::cout << "ClapTrap " << _name
                  << ": can't attack, no energy points left" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        _energyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " gets attacked and takes " << amount
              << " damage!" << std::endl;
    if (_health > amount) {
        _health -= amount;
    } else {
        _health = 0;
        std::cout << "ClapTrap " << _name << " has died skull emoji"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_health == 0) {
        std::cout << "ClapTrap " << _name
                  << ": can't be repaired, is dead skull emoji" << std::endl;
    } else if (_energyPoint == 0) {
        std::cout << "ClapTrap " << _name
                  << ": can't be repaired, no energy points left" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is repaired, gaining " << amount
                  << " health points!" << std::endl;
        _health += amount;
    }
}

void ClapTrap::setName(const std::string &value) { _name = value; }
void ClapTrap::setHealth(const unsigned int &value) {
    _health = value;
    std::cout << "ClapTrap " << _name << " sets health to " << value
              << std::endl;
}
void ClapTrap::setEnergyPoint(const unsigned int &value) {
    _energyPoint = value;
}
void ClapTrap::setAttackDamage(const unsigned &value) {
    std::cout << "ClapTrap " << _name << " sets attack damage to " << value
              << std::endl;
    _attackDamage = value;
}

std::string  ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHealth(void) const { return _health; }
unsigned int ClapTrap::getEnergyPoint(void) const { return _energyPoint; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }
