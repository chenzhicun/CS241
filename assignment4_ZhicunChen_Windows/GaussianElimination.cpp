//
// Created by Zhicun_Chen on 2019/10/5.
//

#include "assignment4.h"
#include <iostream>
#include <vector>
using namespace std;

void GaussianElimination(vector<vector<double>> & coeff,vector<double> & res,int num)
{
    vector<vector<double>> copy(coeff);
    for(int i=0;i<num-1;i++)
    {
        for(int j=i;j<num;j++)
        {
            if(copy[j][i]!=0)
            {
                if(j!=i)
                    swap(copy[i],copy[j]);
                break;
            }
            if(j==num-1)
            {
                cout<<"No unique solution exists!";
                exit(0);
            }
        }
        for(int j=i+1;j<num;j++)
        {
            double times=copy[j][i]/copy[i][i];
            for(int k=0;k<num+1;k++)
                copy[j][k]=copy[j][k]-times*copy[i][k];
        }
    }
    if(copy[num-1][num-1]==0)
    {
        cout<<"No unique solution exists!";
        exit(0);
    }

    res[num-1]=copy[num-1][num]/copy[num-1][num-1];
    for(int i=num-2;i>=0;i--)
    {
        double val=0;
        for(int j=i+1;j<num;j++)
            val+=copy[i][j]*res[j];
        res[i]=(copy[i][num]-val)/copy[i][i];
    }
}