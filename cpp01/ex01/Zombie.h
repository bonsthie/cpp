/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 19:41:46 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
  public:
    Zombie();
    Zombie(const std::string &name);

    void setName(const std::string &name);
    void announce(void) const;

  private:
    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);
