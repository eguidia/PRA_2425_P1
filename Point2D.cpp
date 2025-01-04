#include "Point2D.h"
#include <cmath>

double Point2D::distance(const Point2D& p1, const Point2D& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

