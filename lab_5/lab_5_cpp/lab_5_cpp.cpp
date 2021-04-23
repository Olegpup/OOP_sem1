#include "Line.h"

int main()
{
	Segment a(3, 5, 1, 4);
	cout << "Start of segment: (" << a.GetStart()[0] << ";" << a.GetStart()[1] << ")" << endl;
	cout << "End of segment: (" << a.GetEnd()[0] << ";" << a.GetEnd()[1] << ")" << endl;
	cout << "Length of segment: " << a.GetLength() << endl;
	cout << "Angle of segment with Oy: " << a.GetAngle() << endl;

	return 0;
}