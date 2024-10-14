/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:55:58 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/14 12:43:19 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Log.h"

class AAnimal {
public:
  AAnimal(const std::string &type);
  AAnimal(const AAnimal &src);
  AAnimal(void);
  virtual ~AAnimal(void);

  virtual const std::string &getType(void) const;

  virtual void makeSound(void) const = 0;

  virtual AAnimal &operator=(AAnimal const &src);

protected:
  std::string _type;
};
