#include "Vector.h"

void ShowVectors(MyVector B1, MyVector B2, MyVector B3);

int main()
{
	const double PI = 3.141592;
	MyVector B1 = MyVector();
	MyVector B2 = MyVector(5, PI);
	MyVector B3 = MyVector(B2);
	ShowVectors(B1, B2, B3);
	B2 /= 2;
	ShowVectors(B1, B2, B3);
	B3.Rotate(PI / 4);
	ShowVectors(B1, B2, B3);
	B1 = B3 + B2;
	ShowVectors(B1, B2, B3);

	return 0;
}
void ShowVectors(MyVector B1, MyVector B2, MyVector B3)
{
	cout << "B1: " << B1.GetLenth() << "\t" << B1.GetAngle() << endl;
	cout << "B2: " << B2.GetLenth() << "\t" << B2.GetAngle() << endl;
	cout << "B3: " << B3.GetLenth() << "\t" << B3.GetAngle() << endl;
	cout << "\n\n";
}
