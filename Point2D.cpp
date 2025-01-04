#include "Point2D.h"
#include <cmath>
#include <ostream>  // Asegúrate de incluir esta cabecera

double Point2D::distance(const Point2D &a, const Point2D &b) {
    double dx = a.get_x() - b.get_x();
    double dy = a.get_y() - b.get_y();
    return std::sqrt(dx * dx + dy * dy);  
}

bool operator==(const Point2D &a, const Point2D &b) {
    return a.get_x() == b.get_x() && a.get_y() == b.get_y();  
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.get_x() << ", " << p.get_y() << ")";
    return out;
}

