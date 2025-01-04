#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square();
    Square(std::string color, Point2D* vertices);
    Square(const Square& other);
    Square& operator=(const Square& other);
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual ~Square();

};

#endif

