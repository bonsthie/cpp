/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:57:01 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 09:43:27 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &src);
  ~Dog();

  Dog &operator=(Dog const &src);

private:
  void makeSound(void) const;

  Brain *_brain;
};
