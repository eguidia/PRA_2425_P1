#include "Square.h"
#include "Point2D.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

bool Square::check(Point2D* vertices) {
    double d0 = Point2D::distance(vertices[0], vertices[1]);
    double d1 = Point2D::distance(vertices[1], vertices[2]);
    double d2 = Point2D::distance(vertices[2], vertices[3]);
    double d3 = Point2D::distance(vertices[3], vertices[0]);
    double d01 = Point2D::distance(vertices[0], vertices[2]);
    double d12 = Point2D::distance(vertices[1], vertices[3]);

    return (d0 == d1 && d1 == d2 && d2 == d3 && d01 == d12);
}

Square::Square() : Rectangle("red", new Point2D[4]{
    Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    square.print(out);
    return out;
}

