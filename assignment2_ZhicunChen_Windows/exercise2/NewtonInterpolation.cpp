// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "NewtonInterpolation.h"
#include <vector>
#include <iostream>

using namespace std;

void NewtonInterpolation::DividedDifferenceTable()
{
	int i = num;
	cout.setf(ios::left);
	coefficient.push_back(y[0]);
	vector<double> primary(begin(y),end(y));
	diffe.push_back(primary);
	for (int j = 0; j < 6; j++)
	{
		vector<double> tmp;
		tmp.clear();
		for (int k = 0; k < 6-j; k++)
		{
			double value_tmp;
			value_tmp = (diffe[j][k + 1] - diffe[j][k]) / (x[j + k + 1] - x[k]);
			tmp.push_back(value_tmp);
		}
		diffe.push_back(tmp);
	}
	for (int j = 1; j < 7; j++)
	{
		for (int i = 1; i < j+1; i++)
		{
			cout.width(12);
			cout << diffe[i][j - i];
			
		}
		cout << '\n';
		coefficient.push_back(diffe[j][0]);
	}
}

double NewtonInterpolation::ApproximateValue(double input)
{
	double res = 0;
	res += coefficient[0];
	for (int i = 1; i < 7; i++)
	{
		double factor=coefficient[i];
		for (int j = 0; j < i; j++)
		{
			factor *= (input - x[j]);
		}
		res += factor;
	}
	cout << res;
	return res;
}

// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
