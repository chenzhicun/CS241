#ifndef NEWTONINTERPOLATION_H
#define NEWTONINTERPOLATION_H

#include <vector>

using namespace std;

class NewtonInterpolation
{
private:
	int num = 7;
	double x[7] = { 0.1,0.4,1.0,1.8,2.9,3.2,3.8 };
	double y[7] = { 4.2,3.8,2.5,2.0,-2.0,0.0,-0.3 };
	vector<double> coefficient;
	vector<vector<double>> diffe;
public:
	void DividedDifferenceTable();
	double ApproximateValue(double input);
};

#endif
