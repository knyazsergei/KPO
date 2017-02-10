#pragma once
#include "IShape.h"
#include "Faceted.h"
#include <array>
#include <initializer_list>


class CRectangle :
	public CFaceted
{
public:
	CRectangle(std::array<Point, 4> points);
	CRectangle(std::initializer_list<Point> points);
	~CRectangle();

	double GetSquare() const override;
	double GetPerimeter() const override;
	std::string GetType() const override;
private:
	std::array<Point, 4> m_points;
};

