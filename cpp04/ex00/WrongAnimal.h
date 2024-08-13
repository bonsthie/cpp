/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:55:58 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:33:03 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Log.h"

class WrongAnimal {
public:
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal(void);
  virtual ~WrongAnimal(void);

  const std::string &getType(void) const;

  void makeSound(void) const;

  WrongAnimal &operator=(WrongAnimal const &src);

protected:
  std::string _type;
};
