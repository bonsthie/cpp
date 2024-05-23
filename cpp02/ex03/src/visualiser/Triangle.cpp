/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:24:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "version.h"

#if CPP11

#include "MlxClass.h"
#include "Triangle.h"
#include "mlx.h"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

Triangle::Triangle(Point p1, Point p2, Point p3) : _p1(p1), _p2(p2), _p3(p3) {}

int Triangle::_loop_hook(void __attribute__((unused)) * content) {
    Triangle *self = static_cast<Triangle *>(content);
    return self->_loopPrintTriangle();
}

int Triangle::_loopPrintTriangle(void) {
    int color;

    mlx_mouse_get_pos(_connection, &_mouse_x, &_mouse_y);

    Point mouse(_mouse_x, _mouse_y);
    bsp(_p1, _p2, _p3, mouse) == true ? color = GREEN_COLOR : color = RED_COLOR;
    mlx_clear_window(_connection, _window);
    printTriangle(_p1, _p2, _p3, color);

    printLine(_p1, mouse, 0x44FFFFFF);
    printLine(_p2, mouse, 0x44FFFFFF);
    printLine(_p3, mouse, 0x44FFFFFF);

    printCoord(_p1, WHITE_COLOR);
    printCoord(_p2, WHITE_COLOR);
    printCoord(_p3, WHITE_COLOR);
    printCoord(mouse, WHITE_COLOR);

    return (0);
}

void Triangle::loop_hook() { mlx_loop_hook(_connection, _loop_hook, this); }

#endif
