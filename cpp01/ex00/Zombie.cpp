/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:42:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 19:37:42 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie(const std::string& name) : _name(name) {}

void Zombie::announce(void) const {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
