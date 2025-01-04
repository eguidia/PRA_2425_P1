#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const { return center; }

void Circle::set_center(Point2D p) { center = p; }

double Circle::get_radius() const { return radius; }

void Circle::set_radius(double r) { radius = r; }

void Circle::translate(double incX, double incY) {
    center.set_x(center.get_x() + incX);
    center.set_y(center.get_y() + incY);
}

void Circle::print() const {
    std::cout << "[Circle: color = " << get_color() << "; center = (" 
              << center.get_x() << "," << center.get_y() 
              << "); radius = " << radius << "]";
}

double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    c.print();  // Llama a print(), que ahora es const
    return out;
}

