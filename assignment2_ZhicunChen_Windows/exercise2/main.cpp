#include "NewtonInterpolation.h"
#include <iostream>

using namespace std;

int main()
{
	NewtonInterpolation test;

	test.DividedDifferenceTable();
	double a;
	cin >> a;
	if (cin.fail())
	{
		cout << "error";
		return 0;
	}
	else test.ApproximateValue(a);

	return 0;
}