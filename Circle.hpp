#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
	using Shape::Shape;

	Circle(double r);
	Circle(const Circle& other) = default;
	Circle& operator=(const Circle& other) = default;

	virtual double getArea() const noexcept override;
	virtual double getPerimeter() const noexcept override;
	double getRadius() const;
	virtual void print() const override;

	[[ deprecated ]] double getPi();

private:
	Circle(); // doesn'n allow to call default constructor

	double r_ = 1;
};
