/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:26:17 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 19:44:31 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::Zombie() {}

void Zombie::setName(const std::string &name) { _name = name; }

void Zombie::announce(void) const { std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl; }
