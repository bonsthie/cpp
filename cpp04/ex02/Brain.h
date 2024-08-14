/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:37:42 by bonsthie          #+#    #+#             */
/*   Updated: 2024/08/13 11:12:23 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define IDEAS_SIZE 100

#include <string>
#include "Log.h"

class Brain {
public:
  Brain();
  Brain(const Brain &src);
  ~Brain();

  Brain &operator=(Brain const &src);

  std::string ideas[IDEAS_SIZE];
};
