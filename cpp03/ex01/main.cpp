/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:10 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 14:27:37 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	ScavTrap oui("ahhhhh");
	ScavTrap non(oui);

	non.setName("bhhhhhhhhhhhhhh");
	oui.attack(non.getName());
	non.guardGate();

}
