/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:38:03 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/18 16:36:00 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Wrong number of arguments of " << ac << "sed takes 3 arg <filename> s1 and s2"
                  << std::endl;
        return (1);
    }

	std::string file(av[1]);
	File oui(file);
	oui.sed(av[2], av[3]);
}
