#ifndef POINT2D_H
#define POINT2D_H
#include <ostream>
class Point2D {
private:
    double x, y;

public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    double get_x() const { return x; }
    double get_y() const { return y; }
    void set_x(double new_x) { x = new_x; }  
    void set_y(double new_y) { y = new_y; }  
    static double distance(const Point2D &a, const Point2D &b); 

    bool operator==(const Point2D &other) const {
        return x == other.x && y == other.y;
    }


    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif

