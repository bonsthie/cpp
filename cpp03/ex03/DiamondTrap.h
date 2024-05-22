/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:07:28 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 19:27:00 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &name);
    DiamondTrap(void);
    ~DiamondTrap(void);

    using ScavTrap::attack;
    void whoAmI();

  protected:
    using FragTrap::_attackDamage;
    using FragTrap::_health;
    using ScavTrap::_energyPoint;

  private:
    std::string _name;
};
