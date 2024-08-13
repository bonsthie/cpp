/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:55:58 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/12 20:32:57 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Log.h"

class Animal {
public:
  Animal(const std::string &type);
  Animal(const Animal &src);
  Animal(void);
  virtual ~Animal(void);

  const std::string &getType(void) const;

  virtual void makeSound(void) const;

  Animal &operator=(Animal const &src);

protected:
  std::string _type;
};
