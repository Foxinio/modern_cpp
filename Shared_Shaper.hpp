#pragma once 

#include <memory>

#include "Shape.hpp"

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
	return std::make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

