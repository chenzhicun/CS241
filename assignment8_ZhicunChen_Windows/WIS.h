//
// Created by Zhicun_Chen on 2019/11/5.
//
#include<vector>
using namespace std;

class WIS {
public:
    int WeightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int maximum_profit=0;
        vector<int> p_value(startTime.size());
        for(int i=0;i<p_value.size();++i)
        {
            for(int j=i;j<p_value.size();++j)
            {
                if(endTime[j]<endTime[i])
                {
                    swap(endTime[j],endTime[i]);
                    swap(startTime[j],startTime[i]);
                    swap(profit[j],profit[i]);
                }
            }
        }
        for(int i=0;i<p_value.size();++i)
        {
            for(int j=i;j>=0;--j)
            {
                if(startTime[i]>=endTime[j])
                {
                    p_value[i]=j+1;
                    break;
                }
            }
        }
        vector<int> res(startTime.size()+1);
        res[0]=0;
        for(int i=1;i<=startTime.size();++i)
        {
            res[i]=max(profit[i-1]+res[p_value[i-1]],res[i-1]);
        }
        maximum_profit=res[startTime.size()];
        return maximum_profit;
    }
};