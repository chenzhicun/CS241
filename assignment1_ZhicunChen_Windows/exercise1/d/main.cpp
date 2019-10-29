#include <iostream>
#include <iomanip>
using namespace std;

class tooLowError{};

double ctok(double c);

int main()
{
	double c = 0;
	cout << " Celsius : ";
	cin >> c;
	double k = ctok(c);
	cout <<  " Kelvin : " << k;
	//system("pause");
	return 0;
}

double ctok(double c)
{
	try{	
		if (c<-273.15) throw tooLowError();
		double k = c + 273.15;
		return k;
	}
	catch(tooLowError)
	{
		cout<<"Error reporting!";
		//system("pause");
		exit(0);
	}
}