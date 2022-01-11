/*
1130. Minimum Cost Tree From Leaf Values
Medium

Given an array arr of positive integers, consider all binary trees such that:
- Each node has either 0 or 2 children;
- The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
  (Recall that a node is a leaf if and only if it has 0 children.)
- The value of each non-leaf node is equal to the product of the largest leaf value in
  its left and right subtree respectively.

Among all possible binary trees considered, return the smallest possible sum of the
values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

Example 1:
Input: arr = [6,2,4]
Output: 32
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

struct Result {
    int result;
    int max_child;
};

class Solution {
public:
    Result sum(const vector<int>& arr, int begin, int end) {
        auto res = dp[begin][end];
        if (res.result > 0)
            return res;
        if (begin == end) {
            res = {0, arr[begin]};
            dp[begin][end] = res;
            return res;
        } else if (begin + 1 == end) {
            res = {arr[begin]*arr[end], max(arr[begin], arr[end])};
            dp[begin][end] = res;
            return res;
        }

        int sum = numeric_limits<int>::max();
        int max_child = 0;
        for (int i = 0; begin + i < end; ++i) {
            auto lres = this->sum(arr, begin, begin+i);
            auto rres = this->sum(arr, begin+i+1, end);
            max_child = max({max_child, lres.max_child, rres.max_child});
            sum = min(sum, lres.result + rres.result + lres.max_child * rres.max_child);
        }
        res = {sum, max_child};
        dp[begin][end] = res;

        return res;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, vector<Result>(n, {0,0}));

        auto res = sum(arr, 0, n-1);

        return res.result;
    }

    vector<vector<Result>> dp;
};

int main() {
    Solution sol;
    vector<int> arr;

    // Expected: 32
    arr = {6,2,4};

    cout << "Result: " << sol.mctFromLeafValues(arr) << endl;

    return 0;
}

