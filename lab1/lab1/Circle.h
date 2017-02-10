#pragma once
#include "IShape.h"
class CCircle :
	public IShape
{
public:
	CCircle(Point center, double radius);
	~CCircle();

	double GetSquare() const override;
	double GetPerimeter() const override;
	std::string GetType() const override;
private:
	Point m_center;
	double m_radius;
};

