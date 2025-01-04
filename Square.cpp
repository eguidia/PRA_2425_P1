#include "Square.h"
#include <stdexcept>
#include <iostream>

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (color.empty()) {
        color = "defaultColor";
    }
    this->color = color;
    this->set_vertices(vertices);
}
Square::Square() : Rectangle() { 
}

Square::~Square() {
}

double Square::area() const {
    double side = Point2D::distance(vertices[0], vertices[1]); // Calculas la distancia entre dos vértices
    return side * side; // El área de un cuadrado es lado^2
}

double Square::perimeter() const {
    double side = Point2D::distance(vertices[0], vertices[1]); // Perímetro es 4 veces el lado
    return 4 * side;
}

