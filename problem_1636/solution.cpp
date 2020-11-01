/*
1636. Sort Array by Increasing Frequency
Easy

Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
If multiple values have the same frequency, sort them in decreasing order. Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

Constraints:
1 <= nums.length <= 100
-100 <= nums[i] <= 100
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

using namespace std;

struct Entry {
    Entry(int c, int n): cnt(c), num(n) {}
    int cnt, num;
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int n: nums)
            ++cnt[n];
        vector<Entry> entries;
        for (auto& [k, v]: cnt)
            entries.emplace_back(v, k);
        auto lambda = [] (auto& a, auto& b) {
            return a.cnt < b.cnt || (a.cnt == b.cnt && a.num > b.num);
        };
        sort(begin(entries), end(entries), lambda);
        vector<int> res;
        for (auto& e: entries)
            res.insert(res.end(), e.cnt, e.num);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;

    // Output: {3,1,1,2,2,2}
    nums = {1,1,2,2,2,3};
    res = sol.frequencySort(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,3,3,2,2}
    nums = {2,3,1,3,2};
    res = sol.frequencySort(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {5,-1,4,4,-6,-6,1,1,1}
    nums = {-1,1,-6,4,5,-6,1,4,1};
    res = sol.frequencySort(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
