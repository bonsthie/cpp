/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:10 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 19:02:29 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	DiamondTrap oui("ahhhhh");
	/* DiamondTrap non(oui); */
	
	/* non.setName("bhhhhhhhhhhhhhh"); */
	oui.attack("fsfs");
	oui.highFivesGuys();
	oui.whoAmI();

}
