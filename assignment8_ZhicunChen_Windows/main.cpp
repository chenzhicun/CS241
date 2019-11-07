#include <iostream>
#include <string>
#include <vector>
#include "LCS.h"
#include "WIS.h"
#include "KP.h"
using namespace std;


// For testing
int main(int argc, const char * argv[]) {
    
    //*********** Test Longest Common Subsequence ***********//
    string text1 = "springtime";
    string text2 = "printing";
    LCS lcs = LCS();
    cout << "Test Longest Common Subsequence..." << endl;
    cout << lcs.LongestCommonSubsequence(text1, text2) << endl;
    cout << "The expected output: 6" << endl;
    cout << endl;

    //********** Test Weighted Interval Scheduling **********//
    vector<int> startTime = {1,2,3,4,6};
    vector<int> endTime = {3,5,9,6,9};
    vector<int> profit = {20,20,100,70,60};
    WIS wis = WIS();
    cout << "Test Weighted Interval Scheduling..." << endl;
    cout << wis.WeightedIntervalScheduling(startTime, endTime, profit) << endl;
    cout << "The expected output: 150" << endl;
    cout << endl;

    //*************** Test Knapsack Problem ****************//
    vector<int> weight = {1, 2, 5, 6, 7};
    vector<int> value = {1, 6, 18, 22, 28};
    int W = 11;
    KP kp = KP();
    cout << "Test Knapsack Problem..." << endl;
    cout << kp.KnapsackProblem(weight, value, W) << endl;
    cout << "The expected output: 40" << endl;
    cout << endl;

    return 0;
}
