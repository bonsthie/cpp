/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:18:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 21:12:33 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanB {
  public:
    HumanB(const std::string &name);

    void attack(void) const;
    void setWeapon(Weapon &weapon);

  private:
    std::string _name;
    Weapon      *_weapon;
};
