/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 19:36:46 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie(const std::string& name);

    void announce(void) const;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);
