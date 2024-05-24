/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:47:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/22 23:52:15 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap {
  public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap(void);
    ~ClapTrap(void);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setName(const std::string &value);
    void setHealth(const unsigned int &value);
    void setEnergyPoint(const unsigned int &value);
    void setAttackDamage(const unsigned int &value);

    std::string  getName(void) const;
    unsigned int getHealth(void) const;
    unsigned int getEnergyPoint(void) const;
    unsigned int getAttackDamage(void) const;

  private:
    std::string  _name;
    unsigned int _energyPoint;
	unsigned int _attackDamage;
	unsigned int _health;
};
