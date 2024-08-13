/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:55:24 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 12:49:57 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {

	if (N <= 0)
		return (NULL);
    return (static_cast<Zombie*>(Zombie::operator new[](N, name)));
}
