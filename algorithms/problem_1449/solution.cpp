/*
5399. Form Largest Integer With Digits That Add up to Target
Difficulty: Hard
Given an array of integers cost and an integer target. Return the maximum integer you can paint under the following rules:

The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.

If there is no way to paint any integer given the condition, return "0".

Example 1:
Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9.
You could also paint "997", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5

Example 2:
Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
Output: "85"
Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.

Example 3:
Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
Output: "0"
Explanation: It's not possible to paint any integer with total cost equal to target.

Example 4:
Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
Output: "32211"

Constraints:
cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    string s_max(const string& a, const string& b) {
        if (a.size() == b.size())
            return max(a, b);
        return a.size() > b.size() ? a : b;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target+1);
        unordered_set<int> seen_cost;
        for (int i = n-1; i >= 0; --i) {
            int& c = cost[i];
            auto [ignored, inserted] = seen_cost.insert(c);
            if (!inserted)
                c = -1;
        }
        
        for (int d = 1; d <= target; ++d) {
            for (int i = 0; i < n; ++i) {
                int c = cost[i];
                if (c > 0 && (c == d || (d > c && !dp[d-c].empty()))) {
                    string& dc = dp[d-c];
                    string sa = dc + to_string(i+1);
                    string sb = to_string(i+1) + dc;
                    dp[d] = s_max(dp[d], s_max(sa, sb));
                }
            }

        }

        string& res = dp[target];
        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution sol;
    vector<int> cost;
    int target;

    // Output: "7772"
    cost = {4,3,2,5,6,7,2,5,5}, target = 9;
    cout << sol.largestNumber(cost, target) << endl;
    
    // Output: "85"
    cost = {7,6,5,5,5,6,8,7,8}, target = 12;
    cout << sol.largestNumber(cost, target) << endl;
    
    // Output: "0"
    cost = {2,4,6,2,4,6,4,4,4}, target = 5;
    cout << sol.largestNumber(cost, target) << endl;
    
    // Output: "32211"
    cost = {6,10,15,40,40,40,40,40,40}, target = 47;
    cout << sol.largestNumber(cost, target) << endl;

    cost = {1,1,1,1,1,1,1,1,1}, target = 5000;
    cout << sol.largestNumber(cost, target) << endl;
    
    return 0;
}
