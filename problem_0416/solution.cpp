/*
416. Partition Equal Subset Sum

    User Accepted: 469
    User Tried: 640
    Total Accepted: 483
    Total Submissions: 1563
    Difficulty: Medium

Given a non-empty array containing only positive integers, find if the array
can be partitioned into two subsets such that the sum of elements in both
subsets is equal.

Note:
Both the array size and each of the array element will not exceed 100.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

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
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum >>= 1;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (auto& n: nums) {
            for (int i = sum; i >= n; --i)
                dp [i] |= dp[i-n];
        }
        return dp[sum];
    }
};

int main()
{
    Solution sol;
    vector<int> nums;

    // Expected: true
    nums = {1, 5, 11, 5};

    // 97 / 104 test cases passed.
    // Expected: false
    nums = {1,2,5};

    cout << "Result: " << sol.canPartition(nums) << endl;

    return 0;
}

