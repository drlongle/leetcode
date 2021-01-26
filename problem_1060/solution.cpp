/*
1060. Missing Element in Sorted Array
Medium

Given a sorted array A of unique numbers, find the K-th missing number
starting from the leftmost number of the array.

Example 1:
Input: A = [4,7,9,10], K = 1
Output: 5
Explanation:
The first missing number is 5.

Example 2:
Input: A = [4,7,9,10], K = 3
Output: 8
Explanation:
The missing numbers are [5,6,8,...], hence the third missing number is 8.

Example 3:
Input: A = [1,2,4], K = 3
Output: 6
Explanation:
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.

Note:
1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff <= k) {
                k -= diff -1;
                continue;
            } else
                return nums[i-1] + k;
        }
        return nums.back() + k;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {4,7,9,10}, k = 1;
    cout << sol.missingElement(nums, k) << endl;

    nums = {4,7,9,10}, k = 3;
    cout << sol.missingElement(nums, k) << endl;

    nums = {1,2,4}, k = 3;
    cout << sol.missingElement(nums, k) << endl;

    return 0;
}
