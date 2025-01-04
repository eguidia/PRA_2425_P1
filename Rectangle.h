#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point2D.h"
#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
protected:
    static const int N_VERTICES = 4;
    Point2D* vertices;

public:
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    virtual ~Rectangle();

    Point2D* get_vertices() const;
    void set_vertices(Point2D* new_vertices);

    Point2D get_vertex(int index) const; // Obtener un vértice específico
    Point2D operator[](int index) const; // Acceso mediante índice
    void translate(double dx, double dy); // Mover el rectángulo

    void print(std::ostream& out) const override;
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);
};
#endif
