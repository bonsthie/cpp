/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:15:17 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/12 17:30:46 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), _name(name) {
  this->_health = FragTrap::_health;
  this->_energyPoint = ScavTrap::_energyPoint;
  this->_attackDamage = FragTrap::_attackDamage;

  std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
  *this = other;
  std::cout << "DiamondTrap " << _name << " constructor by copy called"
            << std::endl;
}

DiamondTrap::DiamondTrap(void)
    : ClapTrap("Unnamed_clap_name"), _name("Unnamed") {
  this->_health = FragTrap::_health;
  this->_energyPoint = ScavTrap::_energyPoint;
  this->_attackDamage = FragTrap::_attackDamage;

  std::cout << "DiamondTrap constructor no name called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name :" << _name
            << " ClapTrap name :" << ClapTrap::_name << std::endl;
}

void DiamondTrap::printValue(void) const {
  std::cout << "_energyPoint " << _energyPoint << std::endl;
  std::cout << "_health " << _health << std::endl;
  std::cout << "_attackDamage " << _attackDamage << std::endl;
  std::cout << "_name " << _name << std::endl;
  std::cout << "claptrap _name " << ClapTrap::_name << std::endl;
}
