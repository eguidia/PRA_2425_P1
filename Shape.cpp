#include "Shape.h"

// Constructor por defecto
Shape::Shape() : color("red") {}

// Constructor con color
Shape::Shape(std::string color) {
    if (color != "red" && color != "green" && color != "blue") {
        throw std::invalid_argument("Color inválido");
    }
    this->color = color;
}

// No es necesario definir los métodos `area`, `perimeter`, `translate`, y `print`,
// ya que son métodos virtuales puros, y serán implementados por las clases derivadas.


