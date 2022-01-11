/*
1246. Palindrome Removal
Hard

Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j]
where i <= j, and remove that subarray from the given array. Note that after removing a subarray, the elements
on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array. 

Example 1:
Input: arr = [1,2]
Output: 2

Example 2:
Input: arr = [1,3,4,1,5]
Output: 3
Explanation: Remove [4] then remove [1,3,1] then remove [5].
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
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size()));
        for (int l = 1; l <= static_cast<int>(arr.size()); ++l) {
            for (int i = 0; i + l - 1 < static_cast<int>(arr.size()); ++i) {
                int j = i + l - 1;
                if (l == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + dp[i + 1][j];
                    if (arr[i] == arr[i + 1]) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
                    }
                    for (int k = i + 2; k <= j; ++k) {
                        if (arr[i] == arr[k]) {
                            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                        }
                    }
                }
            }
        }
        return dp[0][arr.size() - 1]; 
    }
};

int main() {
    Solution sol;
    return 0;
}
