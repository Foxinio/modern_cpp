#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	using Shape::Shape;

	Rectangle(double x, double y);
	Rectangle(const Rectangle& other) = default;
	Rectangle& operator=(const Rectangle& other) = default;

	virtual double getArea() const override;
	virtual double getPerimeter() const noexcept override;
	virtual double getX() const final;
	double getY() const;
	virtual void print() const override;

private:
	Rectangle();

	double x_ = 1;
	double y_ = 1;
};
