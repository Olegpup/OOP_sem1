#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class MyVector
{
private:
	double length;
	double angle;
public:
	MyVector();
	MyVector(double r, double fi);
	MyVector(const MyVector& vector);

	double GetLenth();
	double GetAngle();
	void Rotate(double fi);

	MyVector operator+(const MyVector& b);
	void operator/=(double denominator);
};
