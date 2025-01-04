#include "Shape.h"
#include <set>
#include <stdexcept>

const std::set<std::string> Shape::validColors = {"red", "green", "blue", "yellow", "black", "white"};

Shape::Shape(const std::string& color) : color(color) {
    if (validColors.find(color) == validColors.end()) {
        throw std::invalid_argument("Invalid color");
    }
}

void Shape::set_color(const std::string& newColor) {
    if (validColors.find(newColor) == validColors.end()) {
        throw std::invalid_argument("Invalid color");
    }
    color = newColor;
}


