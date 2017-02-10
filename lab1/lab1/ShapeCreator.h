#pragma once
#include <map>
#include <memory>
#include "IShape.h"
#include <functional>
#include <vector>

class CShapeCreator
{

public:
	CShapeCreator();
	~CShapeCreator();

	std::unique_ptr<IShape> MakeShape(std::string line);
private:
	static std::unique_ptr<IShape> MakeCircle(std::string str);
	static std::unique_ptr<IShape> MakeTriangle(std::string str);
	static std::unique_ptr<IShape> MakeRectangle(std::string str);

	static std::vector<std::string> DividBySeparator(char sep, std::string str);
	static void removeCharsFromString(std::string &str, char* charsToRemove);

	std::map < std::string, std::function < std::unique_ptr<IShape>(std::string str) >> m_shapeCreators;
};

