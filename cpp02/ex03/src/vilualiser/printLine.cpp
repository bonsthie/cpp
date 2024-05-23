/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printLine.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:09:38 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "version.h"

#if CPP11

#include "MlxClass.h"

static inline void update_position(Point *point, int sx, int sy, int dx, int dy, int *err) {
    int e2;

    e2 = 2 * *err;
    if (e2 >= dy) {
        *err += dy;
        point->setXint(point->getXint() + sx);
    }
    if (e2 <= dx) {
        *err += dx;
        point->setYint(point->getYint() + sy);
    }
}

static inline int init_s(int x, int y) {
    int s;

    s = -1;
    if (x < y)
        s = 1;
    return (s);
}

void MlxClass::printLine(Point p1, Point p2, int color) {
    int err;

    int sx = init_s(p1.getXint(), p2.getXint());
    int sy = init_s(p1.getYint(), p2.getYint());
    int dx = abs(p2.getXint() - p1.getXint());
    int dy = -abs(p2.getYint() - p1.getYint());
    err = dx + dy;
    while (1) {
        if (p1.getXint() < WIDTH && p1.getYint() < HEIGHT &&
            p1.getXint() >= 0 && p1.getYint() >= 0) {
            mlx_pixel_put(_connection, _window, p1.getXint(), p1.getYint(), color);
        }
        if (p1.getXint() == p2.getXint() && p1.getYint() == p2.getYint())
            break;
        update_position(&p1, sx, sy, dx, dy, &err);
    }
}

#endif
