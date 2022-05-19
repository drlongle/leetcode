/*
493. Reverse Pairs
Hard

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 *
nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3

Constraints:
1 <= nums.length <= 5 * 10^4
-2^31 <= nums[i] <= 23^1 - 1
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<int> temp;
    int find_index(vector<int> &arr, long long num, int lo, int hi) {
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (((long long)arr[mid]) * 2 >= num) {
                hi = mid - 1;
            } else {
                res = mid;
                lo = mid + 1;
            }
        }
        return res;
    }

    int reversePairs(vector<int> &nums, int start, int end) {
        if (start >= end)
            return 0;
        if (start + 1 == end) {
            int res = (nums[start] > 2 * ((long long)nums[end]));
            if (nums[start] > nums[end])
                swap(nums[start], nums[end]);
            return res;
        }

        int mid = (start + end) / 2;
        int res = 0;
        res += reversePairs(nums, start, mid);
        res += reversePairs(nums, mid + 1, end);

        for (int i = start; i <= mid; ++i) {
            int index = find_index(nums, nums[i], mid + 1, end);
            if (index >= 0)
                res += index - mid;
        }

        int i = start, j = mid + 1;
        temp.resize(0);
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            } else
                temp.push_back(nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= end)
            temp.push_back(nums[j++]);
        for (size_t i = 0; i < temp.size(); ++i)
            nums[start + i] = temp[i];

        return res;
    }

    int reversePairs(vector<int> &nums) {
        return reversePairs(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;

    return 0;
}
