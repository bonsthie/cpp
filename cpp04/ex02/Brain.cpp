/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:44 by bonsthie          #+#    #+#             */
/*   Updated: 2024/11/17 20:08:49 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.h"
#include "Log.h"

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
