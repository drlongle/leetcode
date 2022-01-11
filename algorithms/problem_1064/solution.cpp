/*
1064. Fixed Point
Easy

Given an array of distinct integers arr, where arr is sorted in ascending order, return
the smallest index i that satisfies arr[i] == i. If there is no such index, return -1.

Example 1:
Input: arr = [-10,-5,0,3,7]
Output: 3
Explanation: For the given array, arr[0] = -10, arr[1] = -5, arr[2] = 0, arr[3] = 3, thus the output is 3.

Example 2:
Input: arr = [0,2,5,8,17]
Output: 0
Explanation: arr[0] = 0, thus the output is 0.

Example 3:
Input: arr = [-10,-5,3,4,7,9]
Output: -1
Explanation: There is no such i that arr[i] == i, thus the output is -1.

Constraints:
1 <= arr.length < 10^4
-10^9 <= arr[i] <= 10^9

Follow up: The O(n) solution is very straightforward. Can we do better?
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == mid) {
                res = mid;
                hi = mid - 1;
            } else if (arr[mid] < mid)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
