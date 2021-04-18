#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Shared_Shaper.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second)
{
	if (first == nullptr || second == nullptr)
		return false;
	return (first->getArea() < second->getArea());
}

auto perimeterBiggerThan20(shared_ptr<Shape> s)
{
	if (s)
		return (s->getPerimeter() > 20);
	return false;
}

auto areaLessThan10(shared_ptr<Shape> s)
{
	if (s)
		return (s->getArea() < 10);
	return false;
}

void printCollectionElements(const Collection& collection)
{
	for (const auto& it : collection) {
		if (it)
			it->print();
	}
}

void printAreas(const Collection& collection)
{
	for (const auto& it : collection) {
		if (it)
			cout << it->getArea() << std::endl;
	}
}

void findFirstShapeMatchingPredicate(const Collection& collection,
	std::function<bool(shared_ptr<Shape>)> predicate,
	std::string info)
{
	Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
	if (*iter != nullptr)
	{
		cout << "First shape matching predicate: " << info << endl;
		(*iter)->print();
	}
	else
	{
		cout << "There is no shape matching predicate " << info << endl;
	}
}

template<int n, int A = 0, int B = 1>
constexpr int fib = fib<n - 1, B, A + B>;
template <int A, int B> constexpr int fib<1, A, B> = B;
template <int A, int B> constexpr int fib<0, A, B> = A;


int Fib(int n) {
	return n <= 1 ? 1 : (Fib(n - 1) + Fib(n - 2));
}

template<int n>
struct printConstexpr {
	printConstexpr() { std::cout << n << '\n'; }
};

int main()
{
	std::cout << "start" << std::endl;
	//std::cout << Fib(45) << std::endl;
	printConstexpr<fib<45>>();
	auto squareToMove = make_shape<Square>(2.5);
	Collection shapes{
		make_shape<Circle>(2.0),
		make_shape<Circle>(3.0),
		nullptr,
		make_shape<Circle>(4.0),
		make_shared<Rectangle>(10.0, 5.0),
		make_shared<Square>(3.0),
		make_shared<Circle>(4.0),
		make_shared<Circle>(Color::Blue),
		make_shared<Rectangle>(Color::Green)
	};
	shapes[2] = std::move(squareToMove);

	printCollectionElements(shapes);

	cout << "Areas before sort: " << std::endl;
	printAreas(shapes);

	std::sort(shapes.begin(), shapes.end(), [](const shared_ptr<Shape>& first, const shared_ptr<Shape>& second) {
		if (first == nullptr || second == nullptr)
			return false;
		return (first->getArea() < second->getArea());
		});

	cout << "Areas after sort: " << std::endl;
	printAreas(shapes);

	auto square = make_shared<Square>(4.0);
	shapes.push_back(square);

	findFirstShapeMatchingPredicate(shapes, [](shared_ptr<Shape> s) {
		if (s)
			return (s->getPerimeter() > 20);
		return false;
		}, "perimeter bigger than 20");
	int X = 10;
	findFirstShapeMatchingPredicate(shapes, [&X](shared_ptr<Shape> s)
		{
			if (s)
				return (s->getArea() < X);
			return false;
		}, "area less than 10");

	return 0;
}

