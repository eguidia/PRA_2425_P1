#include "Rectangle.h"
#include <stdexcept>
#include <iostream>

Rectangle::Rectangle() : Shape("undefined"), vertices(new Point2D[N_VERTICES]) {}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vertices(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        this->vertices[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& other) : Shape(other.get_color()), vertices(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        this->vertices[i] = other.vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        delete[] vertices;
        vertices = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Rectangle::~Rectangle() {
    delete[] vertices;
}

Point2D* Rectangle::get_vertices() const {
    return vertices;
}

void Rectangle::set_vertices(Point2D* new_vertices) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vertices[i] = new_vertices[i];
    }
}

Point2D Rectangle::get_vertex(int index) const {
    if (index < 0 || index >= N_VERTICES) {
        throw std::out_of_range("Index out of bounds");
    }
    return vertices[index];
}

Point2D Rectangle::operator[](int index) const {
    return get_vertex(index);
}

void Rectangle::translate(double dx, double dy) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vertices[i].set_x(vertices[i].get_x() + dx);
        vertices[i].set_y(vertices[i].get_y() + dy);
    }
}

void Rectangle::print(std::ostream& out) const {
    out << "Rectangle vertices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        out << "(" << vertices[i].get_x() << ", " << vertices[i].get_y() << ") ";
    }
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
    rect.print(out);
    return out;
}

