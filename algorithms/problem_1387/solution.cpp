/*
1387. Sort Integers by The Power Value
Medium

The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.

Example 1:
Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.

Example 2:
Input: lo = 1, hi = 1, k = 1
Output: 1

Example 3:
Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.

Example 4:
Input: lo = 10, hi = 20, k = 5
Output: 13

Example 5:
Input: lo = 1, hi = 1000, k = 777
Output: 570

Constraints:
1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1
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
#include <memory>
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

namespace {
    unordered_map<int, int> dp;
    int power(int num) {
        if (num == 1)
            return 0;
        auto it = dp.find(num);
        if (it != dp.end())
            return it->second;
        if (num % 2 == 0)
            return dp[num] = power(num / 2) + 1;
        else
            return dp[num] = power(3 * num + 1) + 1;
    }
}

class Solution {
public:

    struct Compare {
        bool operator()(int a, int b) {
            int pa = power(a);
            int pb = power(b);
            return pa < pb || (pa == pb && a < b);
        }
    };
    
    int getKth(int lo, int hi, int k) {
        --k;
        vector<int> nums(hi-lo+1);
        iota(begin(nums), end(nums), lo);
        nth_element(begin(nums), begin(nums) + k, end(nums), Compare());

        return nums[k];
    }
};

int main() {
    Solution sol;
    int lo, hi, k;

    // Output: 13
    lo = 12, hi = 15, k = 2;
    cout << sol.getKth(lo, hi, k) << endl;
    
    // Output: 1
    lo = 1, hi = 1, k = 1;
    cout << sol.getKth(lo, hi, k) << endl;
    
    // Output: 7
    lo = 7, hi = 11, k = 4;
    cout << sol.getKth(lo, hi, k) << endl;
    
    // Output: 13
    lo = 10, hi = 20, k = 5;
    cout << sol.getKth(lo, hi, k) << endl;
    
    // Output: 570
    lo = 1, hi = 1000, k = 777;
    cout << sol.getKth(lo, hi, k) << endl;
    
    return 0;
}
