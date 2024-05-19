/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:07:07 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/19 18:19:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef unsigned char u8;

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed &new_value);
    Fixed(const int &new_value);
    Fixed(const float &new_value);
    ~Fixed(void);

	void  setRawBits(int const raw);

    int   getRawBits(void) const;
    float toFloat(void) const;
    int   toInt(void) const;

    Fixed &operator=(const Fixed &);

  private:
    int             _num;
    static const u8 _fractionalPart = 8;
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &value);
