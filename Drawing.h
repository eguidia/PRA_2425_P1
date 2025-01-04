#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"
#include "List.h" // Incluye la interfaz List
#include <iostream>

class Drawing {
private:
    List<Shape*>* shapes;  // Puntero a la lista de figuras

public:
    // Constructor y Destructor
    Drawing();
    ~Drawing();

    // Métodos públicos
    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all();
    double get_area_all_circles();
    void move_squares(double incX, double incY);
};

#endif

