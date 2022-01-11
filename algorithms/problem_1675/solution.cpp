/*
1675. Minimize Deviation in Array
Hard

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element,
and the array will be [1,2,3,2].

If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element,
and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

Example 1:
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2],
then the deviation will be 3 - 2 = 1.

Example 2:
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3],
then the deviation will be 5 - 2 = 3.

Example 3:
Input: nums = [2,10,8]
Output: 3

Constraints:
n == nums.length
2 <= n <= 10^5
1 <= nums[i] <= 10^9
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


namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            hash<int> h;
            return h(p.first) ^ h(p.second);
        }
    };
}

class Solution {
public:
    unordered_set<int> seen;

    int compute(set<int>& s) {
        int res = INT_MAX;
        while (s.size() > 1) {
            auto it1 = s.begin();
            auto it2 = s.rbegin();
            int diff = *it2 - *it1;
            res = min(res, diff);
            if (*it1 & 1 && (*it2 & 1) == 0 && !seen.count(*it1) && !seen.count(*it2)) {
                set<int> cs(s.begin(), s.end());
                int n = *it1;
                cs.erase(n);
                cs.emplace(n << 1);
                seen.emplace(n);
                res = min(res, compute(cs));
            }
            if ((*it2 & 1) == 0 && seen.insert(*it2).second) {
                int n = *it2 / 2;
                s.erase(*it2);
                s.emplace(n);
            } else if ((*it1 & 1) == 1 && seen.insert(*it1).second) {
                int n = *it1;
                s.erase(it1);
                s.emplace(n << 1);
            } else
                break;
        }

        return s.size() > 1 ? res : 0;
    }

    int minimumDeviation(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        seen.clear();

        return compute(s);
    }
};


int main() {
    Solution sol;
    vector<int> nums;

    // Output: 1
    nums = {1,2,3,4};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 3
    nums = {4,1,5,20,3};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 3
    nums = {2,10,8};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 2
    nums = {10,4,3};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 0
    nums = {8,1,2,1};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 315
    nums = {399,908,648,357,693,502,331,649,596,698};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 236
    nums = {610,778,846,733,395};
    cout << sol.minimumDeviation(nums) << endl;

    // Output: 3
    nums = {4,1,5,20,3};
    cout << sol.minimumDeviation(nums) << endl;

    return 0;
}
