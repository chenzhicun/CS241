//
// Created by Zhicun_Chen on 2019/11/5.
//
#include<vector>
using namespace std;

class KP {
public:
    int KnapsackProblem(vector<int> &weight, vector<int> &value, int W) {
        int maximum_value=0;
        vector<vector<int>> res(weight.size()+1);
        for(int i=0;i<weight.size()+1;i++) {
            vector<int> tmp(W + 1);
            res[i]=tmp;
        }
        for(int i=0;i<W+1;i++)
            res[0][i]=0;
        for(int i=0;i<weight.size()+1;i++)
            res[i][0]=0;
        for(int i=1;i<weight.size()+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                res[i][j]=res[i-1][j];
                if(j>=weight[i-1])
                    res[i][j]=max(res[i][j],res[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
        maximum_value=res[weight.size()][W];
        return maximum_value;
    }
};