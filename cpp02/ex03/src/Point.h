/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:41:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/08 18:57:39 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.h"

class Point {
  public:
    Point(const float &x, const float &y);
    Point(const Point &point);
    Point(void);

    Fixed getX(void) const;
    Fixed getY(void) const;
    float getXfloat(void) const;
    float getYfloat(void) const;
    int   getXint(void) const;
    int   getYint(void) const;
    void  setXint(int value);
    void  setYint(int value);

    Point &operator=(const Point &);
    Point  operator-(const Point &other) const;

  private:
    const Fixed _x;
    const Fixed _y;
};
