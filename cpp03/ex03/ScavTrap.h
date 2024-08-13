/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/13 10:24:40 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
  public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap(void);
    ~ScavTrap(void);

    ScavTrap &operator=(const ScavTrap &);

    void attack(const std::string &target);
    void guardGate() const;
};
