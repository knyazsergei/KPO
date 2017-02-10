#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>

CRectangle::CRectangle(std::array<Point, 4> points):
	m_points(points)
{

}

CRectangle::CRectangle(std::initializer_list<Point> points)
{
	std::copy(points.begin(), points.end(), m_points.begin());
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetSquare() const
{
	auto firstLine = sqrt(pow(m_points[0].first - m_points[1].first, 2 + pow(m_points[0].second - m_points[1].second, 2)));
	auto secondLine = sqrt(pow(m_points[2].first - m_points[3].first, 2 + pow(m_points[2].second - m_points[3].second, 2)));
	auto square = firstLine * secondLine;
	return square;
}

double CRectangle::GetPerimeter() const
{
	auto firstLine = SegmentLenght(m_points[0], m_points[1]);
	auto secondLine = SegmentLenght(m_points[1], m_points[2]);
	auto perimeter = ( firstLine + secondLine ) * 2;
	return perimeter;
}

std::string CRectangle::GetType() const
{
	return "RECTANGLE";
}
