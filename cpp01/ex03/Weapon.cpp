/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:24:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 20:27:10 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(const std::string &type) : _type(type) {}

void Weapon::setType(const std::string &type) { _type = type; }

std::string Weapon::getType() const { return (_type); };
