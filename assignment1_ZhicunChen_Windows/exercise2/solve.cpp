#include "solve.h"
#include <cmath>
#include <iostream>
using namespace std;

void solve(double a,double b,double c)
{
	double det = sqrt(b*b-4*a*c);
	double res1 = (-b+det)/(2*a);
	double res2 = (-b-det)/(2*a);
	cout << res1 << ' ' << res2;
}