/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:21:02 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "version.h"

#if CPP11

#    include "MlxClass.h"
#    include "Triangle.h"

int main() {
    Point    a(200.0f, 500.0f);
    Point    b(1500.0f, 100.0f);
    Point    c(1000.0f, 800.0f);
    Triangle triangle(a, b, c);

    triangle.hook();
    triangle.loop_hook();
    triangle.loop();
}
#else

#    include "Point.h"
#    include <iostream>

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "(" << point.getXfloat() << ", " << point.getYfloat() << ")";
    return os;
}

int main() {

    Point a;
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point p1(2.0f, 2.0f); // Inside
    Point p2(6.0f, 6.0f); // Outside

    std::cout << "Point p1 is inside the triangle: "
              << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
    std::cout << "Point p2 is inside the triangle: "
              << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

    return 0;
}
#endif
