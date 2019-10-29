// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class fraction
{
public:
	int numerator;
	int denominator;
public:
	fraction() { fraction(1); }
	fraction(int a);
	friend fraction operator+(const fraction &a, const fraction &b);
	friend fraction operator-(const fraction &a, const fraction &b);
	friend fraction operator*(const fraction &a, const fraction &b);
	friend fraction operator/(const fraction &a, const fraction &b);
	friend ostream & operator<<(ostream & os, fraction & c);
	void simplification();
};

class polynomial
{
public:
	fraction *term;
	int firstOrder;
public:
	polynomial() {};
	polynomial(string & a);
	void div(polynomial & divisor, polynomial & quotient, polynomial & remainder);
	void check();//判断被除数最高次数项系数不为零；
	friend ostream & operator<<(ostream & os, const polynomial & a);
	void changeOrder();
};


#endif
