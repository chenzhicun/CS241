//
// Created by Zhicun_Chen on 2019/10/5.
//

#include "assignment4.h"
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

double norm(vector<double> & res,vector<double> & tmp,int num)
{
    double val=0;
    for(int i=0;i<num;i++)
        val+=(res[i]-tmp[i])*(res[i]-tmp[i]);
    val=sqrt(val);
    return val;
}

void Iter(vector<vector<double>> coeff,vector<double> & now,vector<double> & next,int num)
{
    for(int i=0;i<num;i++)
    {
        double tmp=0;
        for(int j=0;j<num;j++)
        {
            if(j==i) continue;
            tmp+=coeff[i][j]*now[j];
        }
        next[i]=(-tmp+coeff[i][num])/coeff[i][i];
    }
}

void JacobiIteration(vector<vector<double>> & coeff,vector<double> & res,int num)
{
    const double det=0.001;
    const int limitation=10000;
    vector<double> tmp(num);

    cout<<"Input the initial approximation x(0):\n";
    for(int i=0;i<num;i++)
    {
        double tmpval;
        cin>>tmpval;
        res.push_back(tmpval);
    }

    Iter(coeff,res,tmp,num);
    swap(res,tmp);
    if(norm(res,tmp,num)<det)
    {
        for(int i=0;i<num;i++)
            cout<<res[i];
        return;
    }

    for(int i=1;i<limitation;i++)
    {
        Iter(coeff,res,tmp,num);
        swap(res,tmp);
        if(norm(res,tmp,num)<det)
        {
            for(int i=0;i<num;i++)
                cout<<res[i]<<' ';
            return;
        }
        if(i==limitation-1)
        {
            cout<<"Maximum number of iterations exceeded!";
            exit(0);
        }
    }
}