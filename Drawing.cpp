#include "Drawing.h"
#include "ListArray.h"  // Incluye una implementación de la lista (puedes usar ListLinked si lo prefieres)
#include <iostream>

Drawing::Drawing() {
    // Instancia la lista de figuras
    shapes = new ListArray<Shape*>();  // O usa ListLinked dependiendo de tu preferencia
}

Drawing::~Drawing() {
    // Libera la memoria de las figuras
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->add_front(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->add_back(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        std::cout << *(shapes->get(i)) << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double totalArea = 0;
    for (int i = 0; i < shapes->size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i)); // Intenta convertir el puntero a Circle
        if (c != nullptr) {
            totalArea += c->area(); // Suma el área de los círculos
        }
    }
    return totalArea;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes->get(i)); // Intenta convertir el puntero a Square
        if (s != nullptr) {
            s->move(incX, incY); // Mueve el cuadrado
        }
    }
}

