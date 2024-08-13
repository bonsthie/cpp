/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:10 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/12 15:10:57 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>
#include <ostream>

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	ScavTrap yes("ahhhhh");
	ScavTrap no(yes);

	no.setName("bhhhhhhhhhhhhhh");
	yes.attack(no.getName());
	no.guardGate();

	std::cout << std::endl;

	ScavTrap ohNo;
	ohNo = yes;
	yes.attack(no.getName());
	no.guardGate();

}
