/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:26:55 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 19:45:19 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
    int     N = 10;
    Zombie *horde = zombieHorde(N, "le zombie");

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
}
