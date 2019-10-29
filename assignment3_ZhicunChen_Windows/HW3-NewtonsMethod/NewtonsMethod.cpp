#include <iostream>
#include <cmath>
using namespace std;

const double det=0.00001;

double f(double x)
{
    return 10*x*x*x-8.3*x*x+2.295*x-0.21141;
}

double fun(double x)
{
    return 30*x*x-16.6*x+2.295;
}

double NewtonsMethod(double x)
{
    int num=0;
    double tmp=x- f(x) / fun(x);
    cout<<'x'<<num<<':'<<x<<'\n';
    num++;

    while(fabs(x-tmp)>=det)
    {
        cout<<'x'<<num<<':'<<tmp<<'\n';

        num++;
        x=tmp;
        tmp=x-f(x)/fun(x);
    }
    cout<<'x'<<num<<':'<<tmp<<'\n';
    return tmp;
}

int main() {
    NewtonsMethod(0.343036);
    return 0;
}