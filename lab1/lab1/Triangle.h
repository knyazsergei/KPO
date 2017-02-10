#pragma once
#include "IShape.h"
#include "Faceted.h"
#include <array>

class CTriangle :
	public CFaceted
{
public:
	CTriangle(std::array<Point, 3> points);
	CTriangle(std::initializer_list<Point> points);
	~CTriangle();

	double GetSquare() const override;
	double GetPerimeter() const override;
	std::string GetType() const override;
private:
	std::array<Point, 3> m_points;
};

