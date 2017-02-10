#include "stdafx.h"
#include <string>
#include "Controller.h"
#include <iostream>


CController::CController()
{
}


CController::~CController()
{
}

void CController::ReadData(std::string fileName)
{
	m_inputFileStream.open(fileName);
	
	std::string line;
	while (getline(m_inputFileStream, line))
	{
		ParseLine(line);
	}
	m_inputFileStream.close();
}

void CController::PrintData(std::ostream & s)
{
	for (const auto & shape : m_shapes)
	{
		s << shape->GetType() << ": P=" << shape->GetPerimeter() << "; S=" << shape->GetSquare() << std::endl;
	}
}

void CController::SaveData(std::string fileName)
{
	m_outputFileStream.open(fileName, std::ios::out | std::ios::trunc);

	PrintData(m_outputFileStream);

	m_outputFileStream.close();
}

void CController::ParseLine(const std::string & line)
{
	m_shapes.push_back(m_shapeCreator.MakeShape(line));
}
