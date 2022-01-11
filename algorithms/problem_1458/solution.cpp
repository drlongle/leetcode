/*
1458. Max Dot Product of Two Subsequences
Hard

Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Example 2:
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.

Example 3:
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.

Constraints:
1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, numeric_limits<int>::min()));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                int prod = nums1[i]*nums2[j];
                if (i>0 && j>0) {
                    if (prod < 0)
                        dp[i][j] = max(prod,  dp[i-1][j-1]);
                    else
                        dp[i][j] = prod + max(0,  dp[i-1][j-1]);
                } else
                    dp[i][j] = prod;
                if (i>0) dp[i][j] = max(dp[i][j],  dp[i-1][j]);
                if (j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (i>0 && j>0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n1-1][n2-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;

    // Output: 18
    nums1 = {2,1,-2,5}, nums2 = {3,0,-6};
    cout << sol.maxDotProduct(nums1, nums2) << endl;
    
    // Output: 21
    nums1 = {3,-2}, nums2 = {2,-6,7};
    cout << sol.maxDotProduct(nums1, nums2) << endl;
    
    // Output: -1
    nums1 = {-1,-1}, nums2 = {1,1};
    cout << sol.maxDotProduct(nums1, nums2) << endl;

    // Output: 50
    nums1 = {-5,3,-5,-3,1}, nums2 = {-2,4,2,5,-5};
    cout << sol.maxDotProduct(nums1, nums2) << endl;

    // Output: 200
    nums1 = {-3,-8,3,-10,1,3,9}, nums2 = {9,2,3,7,-9,1,-8,5,-1,-1};
    cout << sol.maxDotProduct(nums1, nums2) << endl;
    
    return 0;
}
