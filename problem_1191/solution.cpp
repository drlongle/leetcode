/*
1191. K-Concatenation Maximum Sum
Medium

Given an integer array arr and an integer k, modify the array by repeating it k times.
For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [1,2], k = 3
Output: 9

Example 2:
Input: arr = [1,-2,1], k = 5
Output: 2

Example 3:
Input: arr = [-1,-2], k = 7
Output: 0
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
    static constexpr int mod_const = 1000000007;

    int minSubSum(vector<int>& arr, int begin, int end, int inc) {
        int res = 0;
        int sum = 0;
        for (int i = begin; i != end; i += inc) {
            sum += arr[i];
            res = min(res, sum);
        }
        return res;
    }

    int minSubSum(vector<int>& arr) {
        int res = numeric_limits<int>::max();
        int sum = 0;
        for (size_t i = 0; i != arr.size(); ++i) {
            sum = min(0, sum + arr[i]);
            res = min(res, sum);
        }
        return res;
    }

    int maxSubSum(vector<int>& arr) {
        int res = numeric_limits<int>::min();
        int sum = 0;
        for (size_t i = 0; i != arr.size(); ++i) {
            sum = max(0, sum + arr[i]);
            res = max(res, sum);
        }
        return res;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long res, sum = accumulate(begin(arr), end(arr), 0) % mod_const;
        if (sum > 0) {
            res = (sum * k) % mod_const;
            res -= minSubSum(arr, 0, arr.size(), 1) + minSubSum(arr, arr.size()-1, -1, -1);
        } else {
            res = maxSubSum(arr) % mod_const;
            if (k > 1) {
                res = max(res, (sum - minSubSum(arr)) % mod_const);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
