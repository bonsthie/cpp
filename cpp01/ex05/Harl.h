/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:44:38 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/15 22:10:33 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {
  public:
    void complain(const std::string &level) const;

  private:
    void _debug(void) const;
    void _info(void) const;
    void _warning(void) const;
    void _error(void) const;
};
