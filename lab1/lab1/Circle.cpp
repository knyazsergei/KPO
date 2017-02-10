#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(Point center, double radius):
	m_center(center), m_radius(radius)
{

}

CCircle::~CCircle()
{
}

double CCircle::GetSquare() const
{
	auto square = M_PI * pow(m_radius, 2);
	return square;
}

double CCircle::GetPerimeter() const
{
	auto perimeter = 2 * M_PI * m_radius;
	return perimeter;
}

std::string CCircle::GetType() const
{
	return "CIRCLE";
}
