/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:20:48 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 18:06:38 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

static float crossProduct(const Point &a, const Point &b) {
    return (a.getXfloat() * b.getYfloat() - a.getYfloat() * b.getXfloat());
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    float crossPA_AB = crossProduct(point - a, a - b);
    float crossPB_BC = crossProduct(point - b, b - c);
    float crossPC_CA = crossProduct(point - c, c - a);

    return ((crossPA_AB > 0 && crossPB_BC > 0 && crossPC_CA > 0) ||
            (crossPA_AB < 0 && crossPB_BC < 0 && crossPC_CA < 0));
}
