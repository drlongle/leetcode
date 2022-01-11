/*
548. Split Array with Equal Sum
Medium

Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies
following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5.
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:
1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        unordered_map<int, vector<int>> table;
        int n = nums.size();
        vector<int> prefix(n);
        for (int i = 0, sum = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
            table[sum].push_back(i);
        }

        for (int k = n-1, sum = 0; k > 0; --k) {
            sum += nums[k];
            for (auto i: table[sum]) {
                for (int j = i+2; j < k-2; ++j) {
                    if (prefix[j] - prefix[i+1] == sum && prefix[k-2] - prefix[j+1] == sum) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: True
    nums = {1,2,1,2,1,2,1};
    cout << boolalpha << sol.splitArray(nums) << endl;

    return 0;
}
