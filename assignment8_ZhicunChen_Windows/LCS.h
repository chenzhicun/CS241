//
// Created by Zhicun_Chen on 2019/11/5.
//
#include<vector>
#include<string>
using namespace std;

class LCS {
public:
    int LongestCommonSubsequence(string text1, string text2) {
        int longest_length=0;
        int num1=text1.size();
        int num2=text2.size();
        vector<vector<int>> memo=vector<vector<int>>(num1+1,vector<int>(num2+1,0));
        for(int i=1;i<num1+1;i++)
        {
            for(int j=1;j<num2+1;j++)
            {
                if(text1[i]==text2[j])
                {
                    memo[i][j]=memo[i-1][j-1]+1;
                }
                else
                {
                    memo[i][j]=memo[i-1][j]>memo[i][j-1]?memo[i-1][j]:memo[i][j-1];
                }
            }
        }
        longest_length=memo[num1][num2];
        return longest_length;
    }
};