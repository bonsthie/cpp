/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:44 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 11:38:30 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.h"

Brain::Brain() {
	LOG("Brain constructor empty")
}

Brain::Brain(const Brain &src) {
	LOG("Brain constructor by copy")
	*this = src;
}

Brain::~Brain() {
	LOG("Brain destructor empty")
}

Brain &Brain::operator=(Brain const &src) {
    if (this == &src)
		return *this;
	for (size_t i = 0; i < IDEAS_SIZE; ++i) {
		this->ideas[i] = src.ideas[i];
	}
    return *this;
}
