/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/12 14:55:22 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
  public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap(void);
    ~FragTrap(void);
	
    FragTrap &operator=(const FragTrap &);

    void highFivesGuys(void);
};
