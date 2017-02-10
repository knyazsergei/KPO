#pragma once
#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include "IShape.h"
#include "ShapeCreator.h"

class CController
{
public:
	CController();
	~CController();

	void ReadData(std::string fileName);
	void PrintData(std::ostream & s);
	void SaveData(std::string fileName);
private:
	void ParseLine(const std::string & line);

	std::ifstream m_inputFileStream;
	std::ofstream m_outputFileStream;
	CShapeCreator m_shapeCreator;

	std::vector<std::unique_ptr<IShape>> m_shapes;
};

