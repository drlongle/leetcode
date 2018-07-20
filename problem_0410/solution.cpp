/*
410. Split Array Largest Sum

    Total Accepted: 186
    Total Submissions: 1466
    Difficulty: Medium

Given an array which consists of non-negative integers and an integer m, you
can split the array into m non-empty continuous subarrays. Write an algorithm
to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 <= m <= length(nums) <= 14,000.

Examples:

Input:
nums = [1,2,3,4,5]
m = 2

Output:
9

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5],
where the largest sum among the two subarrays is only 9.

 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:

    int splitArray(vector<int>& nums, int m) {
        int nsize = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(nsize, numeric_limits<int>::max()));
        vector<int> prefix(nsize, 0);
        for (int i = 0; i < nsize; ++i) {
            prefix[i] = nums[i] + (i > 0 ? prefix[i-1] : 0);
            dp[1][i] = prefix[i];
        }

        for (int i = 2; i <= m; ++i) {
            for (int j = 1; j < nsize; ++j) {
                int minmaxsum = max(nums[j], dp[i-1][j-1]);
                for (int k = 0; k < j; ++k) {
                    int temp = max(dp[i-1][k], prefix[j] - prefix[k]);
                    minmaxsum = min(temp, minmaxsum);
                }
                dp[i][j] = minmaxsum;
            }
        }

        return dp[m][nsize-1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int m;

    nums = {1,2,3,4,5};
    m = 2;

    nums = {1,2147483646};
    m = 1;

    cout << "Result: " << sol.splitArray(nums, m) << endl;

    return 0;
}

