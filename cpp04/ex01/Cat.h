/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:57:01 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 11:35:31 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.h"
#include "Brain.h"

typedef unsigned char uint8_t;

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  void setBrainIdear(const std::string &idea, uint8_t offset);
  std::string getBrainIdear(uint8_t offset);

  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;

  Brain *_brain;
};
