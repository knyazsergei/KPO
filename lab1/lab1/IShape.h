#pragma once
#include <utility>
#include <string>
using Point = std::pair<double, double>;

class IShape
{
public:
	IShape();
	~IShape();

	virtual double GetSquare() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetType() const = 0;
};

