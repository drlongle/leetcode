/*
624. Maximum Distance in Arrays
Medium

You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and calculate the distance.
We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array
and pick 5 in the second array.

Example 2:
Input: arrays = [[1],[1]]
Output: 0

Example 3:
Input: arrays = [[1],[2]]
Output: 1

Example 4:
Input: arrays = [[1,4],[0,5]]
Output: 4

Constraints:
m == arrays.length
2 <= m <= 10^5
1 <= arrays[i].length <= 500
-10^4 <= arrays[i][j] <= 10^4
arrays[i] is sorted in ascending order.
There will be at most 10^5 integers in all the arrays.
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
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), res = 0;
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            for (int n: arrays[i]) {
                nums.emplace_back(n, i);
            }
        }

        if (n == 2 && arrays[1].size() == 1)
            return max(abs(arrays[0][0] - arrays[1][0]), abs(arrays[0].back() - arrays[1][0]));

        sort(begin(nums), end(nums));
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i].second != nums[j].second) {
                res = nums[j].first - nums[i].first;
                break;
            }
            if (nums[i+1].first - nums[i].first <=  nums[j].first - nums[j-1].first)
                ++i;
            else
                --j;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
