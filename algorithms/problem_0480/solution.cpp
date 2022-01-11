/*
480. Sliding Window Median
Hard

The median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4}, the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of
the actual value will be accepted.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

Example 2:
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

Constraints:

1 <= k <= nums.length <= 10^5
2^31 <= nums[i] <= 2^31 - 1
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

    template <typename Compare> void erase(map<int, int, Compare>& ma, int key, int& sz) {
        auto it = ma.find(key);
        if (--it->second == 0)
            ma.erase(it);
        --sz;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        map<int, int, greater<int>> bottom;
        map<int, int, less<int>> top;
        vector<double> res;
        int tsize = 0, bsize = 0;

        auto adjust = [&] () {
            if (tsize - bsize == 2) {
                int t = top.begin()->first;
                ++bottom[t];
                ++bsize;
                erase(top, t, tsize);
            } else if (tsize < bsize) {
                int b = bottom.begin()->first;
                erase(bottom, b, bsize);
                ++top[b];
                ++tsize;
            }
        };

        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            int n = nums[i];
            if (i >= k) {
                int prev = nums[i-k];
                if (bottom.count(prev))
                    erase(bottom, prev, bsize);
                else
                    erase(top, prev, tsize);
            }
            adjust();

            if (bsize < tsize) {
                int t = top.begin()->first;
                if (n < t) {
                    ++bottom[n];
                    ++bsize;
                } else {
                    ++bottom[t];
                    ++bsize;
                    erase(top, t, tsize);
                    ++top[n], ++tsize;
                }
                adjust();
                if (i >= k - 1) {
                    double d = top.begin()->first;
                    res.push_back((d + bottom.begin()->first)/ 2);
                }
            } else {
                if (bottom.empty()) {
                    ++top[n];
                    ++tsize;
                } else {
                    int b = bottom.begin()->first;
                    if (n > b) {
                        ++top[n];
                        ++tsize;
                    } else {
                        ++top[b];
                        ++tsize;
                        erase(bottom, b, bsize);
                        ++bottom[n], ++bsize;
                    }
                }
                adjust();
                if (i >= k-1)
                    res.push_back(top.begin()->first);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;
    vector<double> res;

    // Output: {1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000}
    nums = {1,3,-1,-3,5,3,6,7}, k = 3;
    res = sol.medianSlidingWindow(nums, k);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    // Output: {2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000}
    nums = {1,2,3,4,2,3,1,4,2}, k = 3;
    res = sol.medianSlidingWindow(nums, k);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    // Output: 2.5
    nums = {1,4,2,3}, k = 4;
    res = sol.medianSlidingWindow(nums, k);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    nums = {2147483647,1,2,3,4,5,6,7,2147483647}, k = 2;
    res = sol.medianSlidingWindow(nums, k);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    // [8.00000,6.00000,8.00000,8.00000,5.00000]
    nums = {7,0,3,9,9,9,1,7,2,3}, k = 6;
    res = sol.medianSlidingWindow(nums, k);
    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    return 0;
}
