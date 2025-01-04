#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape {
protected:
    std::string color;

public:
    Shape() : color("red") {}

    Shape(std::string color) {
        if (color != "red" && color != "green" && color != "blue") {
            throw std::invalid_argument("Invalid color");
        }
        this->color = color;
    }

    std::string get_color() const {
        return color;
    }

    void set_color(std::string c) {
        if (c != "red" && c != "green" && c != "blue") {
            throw std::invalid_argument("Invalid color");
        }
        color = c;
    }

    virtual double area() const = 0;           // Método virtual puro
    virtual double perimeter() const = 0;      // Método virtual puro
    virtual void translate(double incX, double incY) = 0;  // Método virtual puro
    virtual void print() = 0;                  // Método virtual puro

};

#endif
