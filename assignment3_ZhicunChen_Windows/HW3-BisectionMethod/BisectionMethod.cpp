#include <iostream>
#include <cmath>
using namespace std;

const double det=0.00001;

double calculate(double x)
{
    return 10*x*x*x-8.3*x*x+2.295*x-0.21141;
}

double BisectionMethod(double a, double b)
{
    double mid=0;
    int num=0;

    while(fabs(a-b)>=det)
    {
        mid=(a+b)/2;
        cout<<'x'<<num<<':'<<mid<<'\n';
        num++;
        if(calculate(mid)==0) return mid;
        else
        {
            if(calculate(mid)*calculate(a)<0) b=mid;
            else a=mid;
        }
    }
    return mid;
}

int main() {
    BisectionMethod(0.28516,0.400912);
    return 0;
}
