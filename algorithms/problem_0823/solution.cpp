/*
823. Binary Trees With Factors
Medium

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times.
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large
so return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:
1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
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
    using ll = long long;

    vector<ll> dp;
    static constexpr ll MOD = 1000000007;

    int find_index(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size()-1;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (arr[mid] == k)
                return mid;
            if (arr[mid] < k)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
    }

    ll count(vector<int>& arr, int i) {
        ll& res = dp[i];
        if (res >= 0)
            return res;
        res = 1;
        int n = arr[i], lim = sqrt(n);
        for (int j = 0; j < i && arr[j] <= lim; ++j) {
            if (n % arr[j])
                continue;
            int k = find_index(arr, n / arr[j]);
            if (k >= 0) {
                res = (res + (k != j ? 2 : 1) * count(arr, j) * count(arr, k)) % MOD;
            }
        }

        return res;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        dp.resize(n, -1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + count(arr, i)) % MOD;
        }

        return res;
    }
};

int main() {
    vector<int> arr;

    // Output: 3
    {
        Solution sol;
        arr = {2,4};
        cout << sol.numFactoredBinaryTrees(arr) << endl;
    }

    // Output: 7
    {
        Solution sol;
        arr = {2, 4, 5, 10};
        cout << sol.numFactoredBinaryTrees(arr) << endl;
    }

    // Output: 12
    {
        Solution sol;
        arr = {18, 3, 6, 2};
        cout << sol.numFactoredBinaryTrees(arr) << endl;
    }

    return 0;
}
