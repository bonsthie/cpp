/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:19:26 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 20:51:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanA {
  public:
    HumanA(const std::string &name, Weapon &wepon);

    void attack(void) const;

  private:
    std::string _name;
    Weapon     &_weapon;
};
