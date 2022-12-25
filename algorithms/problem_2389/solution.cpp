/*
2389. Longest Subsequence With Limited Sum
Easy

You are given an integer array nums of length n, and an integer array queries of
length m.

Return an array answer of length m where answer[i] is the maximum size of a
subsequence that you can take from nums such that the sum of its elements is
less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that
2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven
that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven
that 4 is the maximum size of such a subsequence, so answer[2] = 4.

Example 2:
Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less
than or equal to 1, so answer[0] = 0.

Constraints:
n == nums.length
m == queries.length
1 <= n, m <= 1000
1 <= nums[i], queries[i] <= 10^6
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
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        sort(begin(nums), end(nums));
        vector<int> res;
        for (int q : queries) {
            int i = 0, sz = nums.size();
            for (int sum = 0; i < sz; ++i) {
                sum += nums[i];
                if (sum > q)
                    break;
            }
            res.push_back(i);
        }

        return res;
    }
};

int main() { return 0; }
