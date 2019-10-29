#include "polynomial.h"
#include <string>

extern int highest;

fraction::fraction(int a)
{
	numerator = a;
	denominator = 1;
}

void fraction::simplification()
{
	int a = (numerator > 0) ? numerator:-numerator;
	int b = (denominator > 0) ? denominator : -denominator;

	int tmp = (a > b) ? b : a;

	for (; tmp > 1; --tmp)
	{
		if (numerator%tmp == 0 && denominator%tmp == 0)
		{
			numerator /= tmp;
			denominator /= tmp;
		}
	}
}

fraction operator+(const fraction &a, const fraction &b)
{
	fraction tmp;

	tmp.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
	tmp.denominator = a.denominator*b.denominator;
	tmp.simplification();

	return tmp;
}

fraction operator*(const fraction &a, const fraction &b)
{
	fraction tmp;

	tmp.numerator = a.numerator*b.numerator;
	tmp.denominator = a.denominator*b.denominator;
	tmp.simplification();

	return tmp;
}

fraction operator-(const fraction &a, const fraction &b)
{
	fraction tmp;

	tmp.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
	tmp.denominator = a.denominator*b.denominator;
	tmp.simplification();

	return tmp;
}

fraction operator/(const fraction &a, const fraction &b)
{
	fraction tmp;

	if (b.numerator == 0)
	{
		cout << "error";
		exit(0);
	}

	tmp.numerator = a.numerator*b.denominator;
	tmp.denominator = a.denominator*b.numerator;
	tmp.simplification();

	return tmp;
}

ostream & operator<<(ostream & os, fraction &c)
{
	if (c.numerator == 0) 
	{
		os << 0;
		return os;
	}
	if (c.denominator < 0)
	{
		c.denominator = -c.denominator;
		c.numerator = -c.numerator;
	}
	if (c.denominator != 1)
		os << c.numerator << '/' << c.denominator;
	else
		os << c.numerator;
	return os;
}

polynomial::polynomial(string & a)
{
	firstOrder = 0;
	string::iterator itr;
	for (itr = a.begin(); itr != a.end(); itr++)
		if (*itr == ' ') firstOrder++;

	itr = a.begin();
	term = new fraction[firstOrder + 1];
	int res = 0;

	bool sign = true;
	for (int i = 0; itr != a.end(); itr++)
	{
		if (*itr == ' ')
		{
			if (!sign) res = -res;
			term[i] = fraction(res);
			res = 0;
			i++;
			sign = true;
		}
		else
		{
			if (*itr == '-')
			{
				sign = false;
				continue;
			}
			if (*itr <= '9'&&*itr >= '0')
			{
				res *= 10;
				res += (*itr - '0');
			}
			else
			{
				cout << "error";
				exit(0);
			}
		}
	}
	if (!sign) res = -res;
	sign = true;
	term[firstOrder] = res;
}

void polynomial::check()
{
	if (term[0].numerator == 0)
	{
		cout << "error";
		exit(0);
	}
}

ostream& operator<<(ostream &os, const polynomial &a)
{
	int i = 0;
	while (a.term[i].numerator == 0)
		i++;
	if (i > highest)
	{
		os << 0;
		return os;
	}
	for (int j = 0; j < a.firstOrder+1; j++)
		os << a.term[i + j] << ' ';

	return os;
}

void polynomial::changeOrder()
{
	int n = firstOrder;
	for (int i = 0; i < n; i++)
	{
		if (term[i].numerator == 0) firstOrder--;
		else break;
	}
}

void polynomial::div(polynomial & divisor, polynomial & quotient, polynomial & remainder)
{
	
	quotient.firstOrder = firstOrder - divisor.firstOrder;
	quotient.term = new fraction[quotient.firstOrder + 1];
	int n = 0;
	while (divisor.term[n].numerator == 0) n++;
	for (int i = 0; i <= quotient.firstOrder; i++)
	{
		quotient.term[i] = term[i] / divisor.term[n];
		for (int j = n; j <= n+divisor.firstOrder; j++)
		{
			term[i + j - n] = term[i + j - n] - divisor.term[j] * quotient.term[i];
		}
	}

	changeOrder();
	remainder = *this;
}
