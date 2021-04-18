#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color color) :
   color(color) {}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
