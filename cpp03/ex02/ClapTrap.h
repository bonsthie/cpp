/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:47:58 by babonnet          #+#    #+#             */
/*   Updated: 2025/02/03 15:16:58 by babonnet         ###   ########.fr       */
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

    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    virtual void setName(const std::string &value);
    virtual void setHealth(const unsigned int &value);
    virtual void setEnergyPoint(const unsigned int &value);
    virtual void setAttackDamage(const unsigned int &value);

    virtual std::string  getName(void) const;
    virtual unsigned int getHealth(void) const;
    virtual unsigned int getEnergyPoint(void) const;
    virtual unsigned int getAttackDamage(void) const;

    ClapTrap &operator=(const ClapTrap &);

  protected:
    std::string  _name;
    unsigned int _energyPoint;
    unsigned int _attackDamage;
    unsigned int _health;
};
