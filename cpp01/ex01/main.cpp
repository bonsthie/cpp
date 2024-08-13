/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:26:55 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:06:45 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
  int N = 10;
  Zombie *horde = zombieHorde(N, "one zombie");

  for (int i = 0; i < N; i++)
    horde[i].announce();

  Zombie::operator delete[](horde);
}
