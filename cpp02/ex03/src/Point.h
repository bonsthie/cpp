/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:41:58 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 17:22:18 by babonnet         ###   ########.fr       */
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
	void setXint(int value);
	void setYint(int value);

    Point &operator=(const Point &);
    Point  operator-(const Point &other) const;

  private:
    Fixed _x;
    Fixed _y;
};
