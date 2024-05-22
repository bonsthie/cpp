#include "Point.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getXfloat() << ", " << point.getYfloat() << ")";
    return os;
}

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main() {
    Point a;
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point p1(2.0f, 2.0f);  // Inside
    Point p2(6.0f, 6.0f);  // Outside

    std::cout << "Point p1 is inside the triangle: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
    std::cout << "Point p2 is inside the triangle: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

    return 0;
}
