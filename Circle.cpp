#include "Circle.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Circle::Circle(double r) :
	Shape(Color::Red), r_(r) { }

double Circle::getArea() const noexcept
{
	return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
	return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
	return r_;
}

void Circle::print() const
{
	std::cout << "Circle: radius: " << getRadius() << std::endl
		<< "          area: " << getArea() << std::endl
		<< "     perimeter: " << getPerimeter() << std::endl;
}

double Circle::getPi() {
	return getPerimeter() / (2 * r_);
}