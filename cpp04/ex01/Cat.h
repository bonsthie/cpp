/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:57:01 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 09:40:54 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;

  Brain *_brain;
};
