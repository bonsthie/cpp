/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:10 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/21 15:43:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	FragTrap oui("ahhhhh");
	FragTrap non(oui);

	non.setName("bhhhhhhhhhhhhhh");
	oui.attack(non.getName());
	oui.highFivesGuys();

}
