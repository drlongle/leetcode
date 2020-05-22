/*
1444. Number of Ways of Cutting a Pizza
Hard

Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:
Input: pizza = ["A..","A..","..."], k = 1
Output: 1

Constraints:
1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza consists of characters 'A' and '.' only.
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
    static constexpr int MOD = 1000000007;

    int count(int x1, int y1, int x2, int y2) {
        return prefix[x2][y2] - (x1 > 0 ? prefix[x1-1][y2] : 0)
            - (y1 > 0 ? prefix[x2][y1-1] : 0) + (x1 > 0 && y1 > 0 ? prefix[x1-1][y1-1] : 0);
    }

    vector<vector<int>> prefix;
    int ways(vector<string>& pizza, int K) {
        int m = pizza.size(), n = pizza[0].size();

        prefix.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0, sum = 0; j < n; ++j) {
                sum += (pizza[i][j] == 'A');
                prefix[i][j] = sum + (i > 0 ? prefix[i-1][j] : 0);
            }
        }

        if (K == 1)
            return prefix[m-1][n-1] > 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        auto ndp(dp);

        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int cnt = 0;
                    for (int x =i+1; x < m; ++x) {
                        if (count(i, j, x-1, n-1) > 0) {
                            if (k == 2)
                                cnt = (cnt + (count(x, j, m-1, n-1) > 0)) % MOD;
                            else
                                cnt = (cnt + dp[x][j]) % MOD;
                        }
                    }
                    for (int y = j+1; y<n; ++y) {
                        if (count(i, j, m-1, y-1) > 0) {
                            if (k == 2)
                                cnt = (cnt + (count(i, y, m-1, n-1) > 0)) % MOD;
                            else
                                cnt = (cnt + dp[i][y]) % MOD;
                        }
                    }
                    ndp[i][j] = cnt;
                }
            }
            swap(dp, ndp);
        }
        
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    vector<string> pizza;
    int k;

    // Output: 3 
    pizza = {"A..","AAA","..."}, k = 3;
    cout << sol.ways(pizza, k) << endl;
    
    // Output: 1
    pizza = {"A..","AA.","..."}, k = 3;
    cout << sol.ways(pizza, k) << endl;
    
    // Output: 1
    pizza = {"A..","A..","..."}, k = 1;
    cout << sol.ways(pizza, k) << endl;
    

    return 0;
}
