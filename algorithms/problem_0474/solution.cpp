/*
474. Ones and Zeroes
Medium

In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.

Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10",”0001”,”1”,”0”

Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
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
#include <memory>
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

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator() (const pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)), new_dp(m+1, vector<int>(n+1));
        int res = 0;

        set<pair<int, int>> points{{0,0}};
        for (auto& st: strs) {
            int sz = st.size();
            int zeroes = 0, ones = 0;
            for (int k = 0; k < sz; ++k) {
                if (st[k] == '0')
                    ++zeroes;
                else
                    ++ones;
            }
            set<pair<int, int>> skip;
            for (auto& [i, j]: points) {
                int x = i + zeroes, y = j + ones;
                if (x <= m && y <= n && skip.count({i, j}) == 0) {

                    new_dp[x][y] = max(dp[x][y], dp[i][j] + 1);
                    res = max(res, new_dp[x][y]);
                    auto [it, inserted] = points.emplace(x, y);
                    if (inserted)
                        skip.emplace(x, y);
                }
            }
            dp = new_dp;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs;
    int m, n;

    // Output: 4
    strs = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3;
    cout << sol.findMaxForm(strs, m, n) << endl;
    
    // Output: 2
    strs = {"10", "0", "1"}, m = 1, n = 1;
    cout << sol.findMaxForm(strs, m, n) << endl;

    // Expcted: 4
    strs = {"0","0","1","1"};
    m = 2;
    n = 2;
    cout << sol.findMaxForm(strs, m, n) << endl;
    
    // Output: 17
    strs = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
    m = 9;
    n = 80;
    cout << sol.findMaxForm(strs, m, n) << endl;

    // Expected: 3
    strs = {"10","0001","111001","1","0"};
    m = 4, n = 3;
    cout << sol.findMaxForm(strs, m, n) << endl;
    
    return 0;
}
