/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:07:28 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/12 17:24:19 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap {
  public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &name);
    DiamondTrap(void);
    ~DiamondTrap(void);
	
	void printValue(void) const;
	void whoAmI();
  private:
    std::string _name;
};
