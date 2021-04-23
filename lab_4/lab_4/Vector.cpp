#include "Vector.h"

MyVector::MyVector()
{
	length = 0;
	angle = 0;
}
MyVector::MyVector(double r, double fi)
{
	length = r;
	angle = fi;
}
MyVector::MyVector(const MyVector& vector)
{
	this->length = vector.length;
	this->angle = vector.angle;
}
double MyVector::GetLenth()
{
	return length;
}
double MyVector::GetAngle()
{
	return angle;
}
void MyVector::Rotate(double fi)
{
	angle += fi;
}
MyVector MyVector::operator+(const MyVector& b)
{
	double a_length = this->length;
	double b_length = b.length;
	double a_angle = this->angle;
	double b_angle = b.angle;
	double sum_length = sqrt(a_length * a_length + b_length * b_length + 2 * a_length * b_length * cos(b_angle - a_angle));
	double sum_angle = atan(b_length * sin(b_angle - a_angle) / (a_length + b_length * cos(b_angle - a_angle))) + a_angle;

	return MyVector(sum_length, sum_angle);
}
void MyVector::operator/=(double denominator)
{
	length /= denominator;
}
