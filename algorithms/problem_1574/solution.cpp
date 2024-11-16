/*
1574. Shortest Subarray to be Removed to Make Array Sorted
Medium

Given an integer array arr, remove a subarray (can be empty) from arr such that
the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

Example 1:
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The
remaining elements after that will be [1,2,3,3,5] which are sorted. Another
correct solution is to remove the subarray [3,10,4].

Example 2:
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single
element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or
[4,3,2,1].

Example 3:
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any
elements.

Constraints:
1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        vector<int> l, r;

        if (ranges::is_sorted(arr))
            return 0;

        auto sz = arr.size();
        for (int a : arr) {
            if (l.empty() || l.back() <= a)
                l.push_back(a);
            else
                break;
        }

        // auto reversed = arr | std::views::reverse;

        std::reverse(arr.begin(), arr.end());
        for (int a : arr) {
            if (r.empty() || r.back() >= a)
                r.push_back(a);
            else
                break;
        }
        reverse(r.begin(), r.end());

        size_t res = sz - 1;
        for (size_t i = 0; i < l.size(); ++i) {
            auto it = lower_bound(r.begin(), r.end(), l[i]);
            size_t removed = l.size() - i - 1 + it - r.begin();
            res = min(res, removed);
        }
        res = res + sz - l.size() - r.size();
        if (sz - l.size() < res)
            res = sz - l.size();
        if (sz - r.size() < res)
            res = sz - r.size();

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 3
    arr = {1, 2, 3, 10, 4, 2, 3, 5};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;

    // Output: 4
    arr = {5, 4, 3, 2, 1};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;

    // Output: 0
    arr = {1, 2, 3};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;

    // Output 1
    arr = {2, 1};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;

    // Output 8
    arr = {16, 10, 0, 3, 22, 1, 14, 7, 1, 12, 15};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;

    return 0;
}
