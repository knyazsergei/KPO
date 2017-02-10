#pragma once
#include "IShape.h"
class CFaceted :
	public IShape
{
public:
	CFaceted();
	~CFaceted();

	virtual double GetSquare() const = 0;
	virtual double GetPerimeter() const = 0;
protected:
	double SegmentLenght(Point first, Point second)const;
};

