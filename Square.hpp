#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
	using Rectangle::Rectangle;

	Square(double x);
	Square(const Square& other) = default;
	Square& operator=(const Square& other) = default;

	virtual double getArea() const override;
	virtual double getPerimeter() const noexcept override;
	void print() const override;

private:
	double getY() const = delete; // should not have Y dimension
	Square();
};
