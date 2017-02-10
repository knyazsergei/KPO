#include "stdafx.h"
#include <sstream>
#include <string>
#include <array>
#include "ShapeCreator.h"

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>

CShapeCreator::CShapeCreator()
{
	m_shapeCreators["CIRCLE"] = &CShapeCreator::MakeCircle;
	m_shapeCreators["TRIANGLE"] = &CShapeCreator::MakeTriangle;
	m_shapeCreators["RECTANGLE"] = &CShapeCreator::MakeRectangle;
}


CShapeCreator::~CShapeCreator()
{
}

std::unique_ptr<IShape> CShapeCreator::MakeShape(std::string line)
{
	auto parts = DividBySeparator(':', line);
	auto shapeType = parts[0];
	auto shapeData = parts[1];

	return m_shapeCreators[shapeType](shapeData);
}

std::unique_ptr<IShape> CShapeCreator::MakeCircle(std::string str)
{
	removeCharsFromString(str, ": =CRPS");
	auto args = DividBySeparator(';', str);

	auto strCenter = args[0];
	auto strRadius = args[1];

	auto strCenterPoint = DividBySeparator(',', strCenter);

	Point center{ std::stoi(strCenterPoint[0]),std::stoi(strCenterPoint[1]) };
	unsigned radius = std::stoi(strRadius);
	return std::make_unique<CCircle>(center, radius);
}

std::unique_ptr<IShape> CShapeCreator::MakeTriangle(std::string str)
{
	auto args = DividBySeparator(';', str);

	std::array<Point, 3> points;
	for (size_t i = 0;i < args.size(); ++i)
	{
		auto sepPoint = DividBySeparator('=', args[i]);
		auto xyPoint = DividBySeparator(',', sepPoint.back());
		points[i] = Point(std::stoi(xyPoint.front()), std::stoi(xyPoint.back()));
	}

	return std::make_unique<CTriangle>(points);
}

std::unique_ptr<IShape> CShapeCreator::MakeRectangle(std::string str)
{
	auto args = DividBySeparator(';', str);

	std::array<Point, 4> points;
	for (size_t i = 0; i < args.size(); ++i)
	{
		auto sepPoint = DividBySeparator('=', args[i]);
		auto xyPoint = DividBySeparator(',', sepPoint.back());
		points[i] = Point(std::stoi(xyPoint.front()), std::stoi(xyPoint.back()));
	}

	return std::make_unique<CRectangle>(points);
}

std::vector<std::string> CShapeCreator::DividBySeparator(char sep, std::string str)
{
	std::istringstream ss(str);
	std::vector<std::string> result;
	std::string token;

	while (std::getline(ss, token, sep))
	{
		result.push_back(token);
	}

	return result;
}

void CShapeCreator::removeCharsFromString(std::string &str, char* charsToRemove)
{
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) 
	{
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}
