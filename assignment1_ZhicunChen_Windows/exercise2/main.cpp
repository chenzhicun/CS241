#include "solve.h"
#include <iostream>
using namespace std;

int main()
{
	double a,b,c;
	try
	{
		cin >> a >> b >> c;
		if (cin.fail() || a == 0) throw illegalInput();
		if (b * b - 4 * a * c < 0) throw noRealRoots();
	}
	catch(illegalInput)
	{
		cout << "Illegal inputs!";
		//system("pause");
		return 0;
	}
	catch(noRealRoots)
	{
		cout << "b^2-4ac is less than zero!";
		//system("pause");
		return 0;
	}
	solve(a,b,c);
	//system("pause");
	return 0;
}