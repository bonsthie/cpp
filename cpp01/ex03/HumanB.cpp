/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:52:33 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 22:56:33 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack(void) const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " dosen't have a weapon" << std::endl;
}
