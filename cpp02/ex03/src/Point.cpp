/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:52:05 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/08 18:59:44 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float &x, const float &y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Fixed Point::getX(void) const { return _x; }

Fixed Point::getY(void) const { return _y; }

float Point::getXfloat(void) const { return _x.toFloat(); }

float Point::getYfloat(void) const { return _y.toFloat(); }

int Point::getXint(void) const { return _x.toInt(); }

int Point::getYint(void) const { return _y.toInt(); }

void Point::setXint(int value) {
    const_cast<Fixed &>(_x).setRawBits(value << 8);
}

void Point::setYint(int value) {
    const_cast<Fixed &>(_y).setRawBits(value << 8);
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        const_cast<Fixed &>(_x) = other._x;
        const_cast<Fixed &>(_y) = other._y;
    }
    return *this;
}

Point Point::operator-(const Point &other) const {
    return Point(_x.toFloat() - other._x.toFloat(),
                 _y.toFloat() - other._y.toFloat());
}
