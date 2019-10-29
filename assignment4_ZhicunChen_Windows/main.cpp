#include <iostream>
#include <vector>
#include "assignment4.h"
using namespace std;

int main() {
    int unkownsNum = 0;
    int method;

    cout<<"Input the number of equations and unknowns n:";
    cin>>unkownsNum;
    if(cin.fail())
    {
        cerr<<"Invalid input!";
        exit(0);
    }

    vector<vector <double>> coeff;
    vector<double> res(unkownsNum);

    cout<<"Input the augmented matrix of Ax=b as [A b]:\n";
    for(int i=0;i<unkownsNum;i++)
    {
        vector<double> tmp;
        tmp.clear();
        for(int j=0;j<unkownsNum+1;j++)
        {
            double val;cin>>val;
            if(cin.fail())
            {
                cerr<<"Invalid input!";
                exit(0);
            }
            tmp.push_back(val);
        }
        coeff.push_back(tmp);
    }

    GaussianElimination(coeff,res,unkownsNum);
    cout<<"[0] Jacobi Iteration [1] Gaussian Elimination\nChoose a method:";
    cin>>method;

    if(method==0)
    {
        res.clear();
        JacobiIteration(coeff, res, unkownsNum);
    }
    else {
        if (method == 1)
        {
            for (int i = 0; i < unkownsNum; i++)
                cout << res[i] << ' ';
        }
        else {
            cout << "Invalid method number!";
            exit(0);
        }
    }
    return 0;
}