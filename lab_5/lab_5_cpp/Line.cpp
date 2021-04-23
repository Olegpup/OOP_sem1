#include "Line.h"

Line::Line(double x1, double x2, double y1, double y2)
{
    start_coordinates = new double[] {x1, y1};
    end_coordinates = new double[] {x2, y2};
}
double Line::GetLength()
{
    return sqrt((end_coordinates[0]-start_coordinates[0])*(end_coordinates[0]-start_coordinates[0])+(end_coordinates[1]-start_coordinates[1])*(end_coordinates[1]-start_coordinates[1]));
}
double* Line::GetStart()
{
    return start_coordinates;
}
double* Line::GetEnd()
{
    return end_coordinates;
}
Line::~Line()
{
    delete[] start_coordinates;
    delete[] end_coordinates;
}

Segment::Segment(double x1, double x2, double y1, double y2) : Line(x1, x2, y1, y2) {}

double Segment::GetAngle()
{
    return atan((end_coordinates[0] - start_coordinates[0]) / (end_coordinates[1] - start_coordinates[1]));
}
