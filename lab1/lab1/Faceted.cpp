#include "stdafx.h"
#include "Faceted.h"


CFaceted::CFaceted()
{
}


CFaceted::~CFaceted()
{
}

double CFaceted::SegmentLenght(Point first, Point second) const
{
	auto lenght = sqrt(pow(first.first - second.first, 2) + pow(first.second - second.second, 2));
	return lenght;
}
