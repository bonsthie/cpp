/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:18:08 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 21:10:09 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
  public:
    Weapon(const std::string &type);

    void        setType(const std::string &type);
    std::string getType(void) const;

  private:
    std::string _type;
};
