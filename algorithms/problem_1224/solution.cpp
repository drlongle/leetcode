/*
1224. Maximum Equal Frequency
Hard

Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).

Example 1:
Input: nums = [2,2,1,1,5,3,3,5]
Output: 7
Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.

Example 2:
Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
Output: 13

Example 3:
Input: nums = [1,1,1,2,2,2]
Output: 5

Example 4:
Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
Output: 8

Constraints:
2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> counts;
        map<int, set<int>> levels;
        int res = 1;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            int num = nums[i];
            int c = counts[num]++;
            if (c > 0) {
                levels[c].erase(num);
                if (levels[c].empty())
                    levels.erase(c);
            }
            levels[c+1].emplace(num);
            bool match = false;
            if (levels.size() == 2) {
                if (levels.count(1) > 0 && levels[1].size() == 1)
                    match = true;
                else {
                    auto it1 = levels.begin();
                    auto it2 = levels.rbegin();
                    int sz2 = it2->second.size();
                    if (it1->first + 1 == it2->first && sz2 == 1)
                        match = true;
                }
            } else if (levels.size() == 1) {
                if (levels.count(1) > 0 || static_cast<int>(levels.begin()->second.size()) == 1)
                    match = true;
            }
            if (match)
                res = max(res, i+1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 7
    nums = {2,2,1,1,5,3,3,5};

    // Output: 13
    //nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};

    // Output: 5
    //nums = {1,1,1,2,2,2};

    // Output: 8
    //nums = {10,2,8,9,3,8,1,5,2,3,7,6};

    // Output: 2
    //nums = {1,2};

    // Output: 2
    //nums = {1,1};

    cout << "Result: " << sol.maxEqualFreq(nums) << endl;
    
    return 0;
}
