/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:43:24 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:45:25 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(void) {
	Harl harl;

	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("yes");
}
