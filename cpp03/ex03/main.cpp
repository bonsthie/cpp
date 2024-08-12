/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:10 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/12 16:17:22 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
  DiamondTrap oui("ahhhhh");
  oui.printValue();
  oui.attack("bhhhhhhhhhhhhhh");
  std::cout << std::endl;
  /* DiamondTrap non(oui); */

  /* non.setName("bhhhhhhhhhhhhhh"); */
  oui.attack("fsfs");
  oui.highFivesGuys();
  oui.whoAmI();
}
