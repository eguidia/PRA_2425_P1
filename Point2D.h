#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>
#include <ostream>

class Point2D {
private:
    double x, y;

public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    double get_x() const { return x; }
    double get_y() const { return y; }

    void set_x(double x) { this->x = x; }
    void set_y(double y) { this->y = y; }

    void translate(double incX, double incY) {
        x += incX;
        y += incY;
    }

    static double distance(const Point2D& p1, const Point2D& p2);

    friend std::ostream& operator<<(std::ostream& out, const Point2D& p);
    
    bool operator==(const Point2D& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point2D& other) const {
        return !(*this == other);  
    }
};

#endif
