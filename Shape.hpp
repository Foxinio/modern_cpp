#pragma once

enum class Color : unsigned char {
	Blue,
	Red,
	Green
};

class Shape
{
public:
	Color color;

	Shape() = delete;
	Shape(Color color);
	Shape(const Shape&) = default;
	Shape& operator=(const Shape&) = default;
	Shape(Shape&&) noexcept = default;
	Shape& operator=(Shape&&) noexcept = default;

	virtual ~Shape() {}

	virtual double getArea() const = 0;
	virtual double getPerimeter() const noexcept = 0;
	virtual void print() const;
};
