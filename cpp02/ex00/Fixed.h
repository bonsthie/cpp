/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:07:07 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/19 16:21:48 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef unsigned char u8;

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed &new_value);
    ~Fixed(void);

    int  getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(const Fixed &);

  private:
    int             _num;
    static const u8 _fractionalPart = 8;
};
