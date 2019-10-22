/*
1230. Toss Strange Coins
Medium

You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.
Return the probability that the number of coins facing heads equals target if you toss every coin exactly once. 

Example 1:
Input: prob = [0.4], target = 1
Output: 0.40000

Example 2:
Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {

public:
    double probabilityOfHeads(vector<double>& prob, int target) {

        int n = prob.size();
        vector<vector<double>> dp(n, vector<double>(target + 1, 0.0));
        if(target) dp[0][1] = prob[0];
        dp[0][0] = 1.0 - prob[0];
        for(int i = 1; i < n; i ++){
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
            for(int j = 1; j <= target; j ++)
                dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
        }
        return dp[n - 1][target];
    }
};


int main() {
    Solution sol;
    vector<double> prob;
    int target;

    // Output: 0.40000
    prob = {0.4}, target = 1;

    // Output: 0.03125
    prob = {0.5,0.5,0.5,0.5,0.5}, target = 0;

    // Output: 0
    prob = {1,1,1,1,1,1,1,1,1,1}, target = 9;

    // Output: 0.182
    prob = {0.2,0.8,0,0.3,0.5}, target = 3;
    
    cout << "Result: " << sol.probabilityOfHeads(prob, target) << endl;
    
    return 0;
}
