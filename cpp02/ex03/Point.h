/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:41:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/19 23:46:37 by babonnet         ###   ########.fr       */
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

    Point &operator=(const Point &);
    Point  operator-(const Point &other) const;

  private:
    Fixed _x;
    Fixed _y;
};
