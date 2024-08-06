/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 13:47:45 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
public:
  Zombie();
  Zombie(const std::string &name);
  ~Zombie();

  void announce(void) const;

  static void *operator new[](size_t count, const std::string &name);
  static void operator delete[](void *p);

private:
  std::string _name;
};

Zombie *zombieHorde(int N, std::string name);
