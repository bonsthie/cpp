/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:24:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:34:31 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(const std::string &type) : _type(type) {}

void Weapon::setType(const std::string &type) { _type = type; }

const std::string &Weapon::getType() const { return (_type); };
