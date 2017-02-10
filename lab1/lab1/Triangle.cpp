#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(std::array<Point, 3> points):
	m_points(points)
{

}

CTriangle::CTriangle(std::initializer_list<Point> points)
{
	std::copy(points.begin(), points.end(), m_points.begin());
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetSquare() const
{
	auto square = 0.5 * (
		(m_points[0].first - m_points[2].first) * (m_points[1].second - m_points[2].second) -
		(m_points[1].first - m_points[2].first) * (m_points[0].second - m_points[2].second)
	);

	return square;
}

double CTriangle::GetPerimeter() const
{
	auto perimeter = SegmentLenght(m_points[0], m_points[1]) + SegmentLenght(m_points[0], m_points[2]) + SegmentLenght(m_points[1], m_points[2]);
	return perimeter;
}

std::string CTriangle::GetType() const
{
	return "TRIANGLE";
}
