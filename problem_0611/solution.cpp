/*
611. Valid Triangle Number
Medium

Given an integer array nums, return the number of triplets chosen from the array
that can make triangles if we take them as side lengths of a triangle.


Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
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

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int res = 0, lo, hi;
        for (int i = 0, n = nums.size(); i + 2 < n; ++i) {
            for (int j = i + 1; j + 1 < n; ++j) {
                lo = j + 1, hi = n -1;
                int sum = nums[i] + nums[j];
                if (sum <= nums[lo])
                    continue;
                int index = lo;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (sum > nums[mid]) {
                        index = mid;
                        lo = mid + 1;
                    } else
                        hi = mid - 1;
                }
                res += index - j;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 3
    nums = {2,2,3,4};
    cout << sol.triangleNumber(nums) << endl;

    // Output: 4
    nums = {4,2,3,4};
    cout << sol.triangleNumber(nums) << endl;

    return 0;
}
