/*
1223. Dice Roll Simulation
Medium

A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the
generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 

Given an array of integers rollMax and an integer n, return the number of distinct sequences that
can be obtained with exact n rolls.

Two sequences are considered different if at least one element differs from each other.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are
6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2
appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the
final answer is 36-2 = 34.

Example 2:
Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30

Example 3:
Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181
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
    static constexpr int mod_factor = pow(10, 9) + 7;
    static constexpr int mod = 1'000'000'007;
    constexpr int power(int k, int n) {
        int res = 1;
        for (int i = 1; i <= n; ++i)
            res = (res * k) % mod_factor;
        return res;
    }
    
    int countSeries(vector<int>& rollMax, int prev, int n) {
        if (n == 0)
            return 1;
        auto key = pair<int, int>{prev, n};
        auto it = dp.find(key);
        if (it != end(dp))
            return it->second;
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            if (i == prev)
                continue;
            for (int j = 1; j <= rollMax[i] && j <= n; ++j)
                res = (res + countSeries(rollMax, i, n-j)) % mod_factor;
        }
        return dp[key] = res % mod_factor;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        sz = rollMax.size();
        return countSeries(rollMax, -1, n);
    }
    int sz;
    map<pair<int, int>, int> dp;
};

int main() {
    Solution sol;
    vector<int> rollMax;
    int n;

    // Output: 34
    n = 2, rollMax = {1,1,2,2,2,3};
         
    // Output: 30
    //n = 2, rollMax = {1,1,1,1,1,1};

    // Output: 181
    n = 3, rollMax = {1,1,1,2,2,3};

    // Output: 1082
    //n = 4, rollMax = {2,1,1,3,3,2};
        
    // Output: 33573724
    //n = 10, rollMax = {1,1,2,2,2,3};

    cout << "Result: " << sol.dieSimulator(n, rollMax) << endl;
    
    return 0;
}
