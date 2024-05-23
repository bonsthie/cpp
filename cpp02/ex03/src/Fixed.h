/** ************************************************************************** */
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

    void setRawBits(int const raw);

    int                 getRawBits(void) const;
    float               toFloat(void) const;
    int                 toInt(void) const;

    static const Fixed &min(Fixed &a, Fixed &b);
    static Fixed        min(const Fixed &a, const Fixed &b);
    static const Fixed &max(Fixed &a, Fixed &b);
    static Fixed        max(const Fixed &a, const Fixed &b);

    Fixed &operator=(const Fixed &);

    bool operator>(const Fixed &) const;
    bool operator<(const Fixed &) const;
    bool operator>=(const Fixed &) const;
    bool operator<=(const Fixed &) const;
    bool operator==(const Fixed &) const;
    bool operator!=(const Fixed &) const;

    float operator+(const Fixed &) const;
    float operator-(const Fixed &) const;
    float operator*(const Fixed &) const;
    float operator/(const Fixed &) const;

    Fixed &operator--(void);
    Fixed  operator--(int);
    Fixed &operator++(void);
    Fixed  operator++(int);

  private:
    int             _num;
    static const u8 _fractionalPart = 8;
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &value);
