#include <iostream>
#include <iomanip>
using namespace std;

class tooLowError{};

double ctok(double c);

int main()
{
	double c = 0;
	cout << " Celsius : ";
	try{
		cin >> c;
		if (c < -273.15) throw tooLowError();
		}
	catch(tooLowError)
	{
		cout<<"Error reporting!";
		//system("pause");
		return 0;
	}
	double k = ctok(c);
	cout <<  " Kelvin : " << k;
	//system("pause");
	return 0;
}

double ctok(double c)
{
	double k = c + 273.15;
	return k;
}