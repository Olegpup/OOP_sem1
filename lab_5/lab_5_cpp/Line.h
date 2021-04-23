#pragma once

#include <iostream>
#include <cmath>
using namespace std;

class Line
{
protected:
	double* start_coordinates;
	double* end_coordinates;

	Line(double x1, double x2, double y1, double y2);

public:
	double GetLength();
	double* GetStart();
	double* GetEnd();
	~Line();
};

class Segment : public Line
{
public:
	Segment(double x1, double x2, double y1, double y2);
	double GetAngle();
};