#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle();
    Circle(std::string color, Point2D center, double radius);

    Point2D get_center() const;
    void set_center(Point2D p);

    double get_radius() const;
    void set_radius(double r);

    void print() const override;  // Asegúrate de usar override
    void translate(double incX, double incY) override;
    double area() const override;
    double perimeter() const override;

    friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

#endif
