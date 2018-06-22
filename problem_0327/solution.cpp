/*
327. Count of Range Sum

    Total Accepted: 11205
    Total Submissions: 40323
    Difficulty: Hard

Given an integer array nums, return the number of range sums that lie in
[lower, upper] inclusive. Range sum S(i, j) is defined as the sum of the
elements in nums between indices i and j (i <= j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are:
-2, -1, 2. 
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int begin, int end, int lower, int upper) {
        if (begin == end) {
            if (nums[begin] >= lower && nums[end] <= upper)
                return 1;
            else
                return 0;
        }
        int mid = begin + ((end - begin) >> 1);
        int res = countRangeSum(nums, begin, mid, lower, upper)
            + countRangeSum(nums, mid+1, end, lower, upper);
        map<ll, ll> count_sum;
        ll sum = 0;
        for (int i = mid+1; i <= end; ++i) {
            sum += nums[i];
            ++count_sum[sum];
        }
        sum = 0;
        for (int i = mid; i >= begin; --i) {
            sum += nums[i];
            auto it = count_sum.lower_bound(lower - sum);
            while (it != count_sum.end() && it->first <= upper - sum) {
                res += it->second;
                ++it;
            }
        }

        return res;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        else
            return countRangeSum(nums, 0, nums.size()-1, lower, upper);
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> nums;
    int lower, upper;

    // Expected: 3
    nums = {-2, 5, -1}, lower = -2, upper = 2;

    // Expected: 3
    nums = {-2147483647,0,-2147483647,2147483647};
    lower = -564, upper = 3864;

    cout << "Result: " << sol.countRangeSum(nums, lower, upper) << endl;

    return 0;
}

