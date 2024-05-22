/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:52:05 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/20 00:31:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point(void) {}

Point::Point(const float &x, const float &y) : _x(x), _y(y) {}

Point::Point(const Point &point) { *this = point; }

Fixed Point::getX(void) const { return (_x); }

Fixed Point::getY(void) const { return (_y); }

float Point::getXfloat(void) const { return (_x.toFloat()); }

float Point::getYfloat(void) const { return (_y.toFloat()); }

Point &Point::operator=(const Point &value) {
    if (this != &value) {
        _x = value.getX();
        _y = value.getY();
    }
    return (*this);
}

Point Point::operator-(const Point &other) const {
    return Point(_x - other._x, _y - other._y);
}
