#include <iostream>
using namespace std;

double sqr(double num)
{
	return num * num;
}

int main()
{
	double number = 1.2;
	double (*ptr)(double num) = sqr;
	number = ptr(number);
	cout << number << endl;
}