/*
3659. Partition Array Into K-Distinct Groups
Medium

You are given an integer array nums and an integer k.

Your task is to determine whether it is possible to partition all elements of nums into
one or more groups such that:
Each group contains exactly k distinct elements.
Each element in nums must be assigned to exactly one group.
Return true if such a partition is possible, otherwise return false.

Example 1:
Input: nums = [1,2,3,4], k = 2
Output: true
Explanation:
One possible partition is to have 2 groups:
Group 1: [1, 2]
Group 2: [3, 4]
Each group contains k = 2 distinct elements, and all elements are used exactly once.

Example 2:
Input: nums = [3,5,2,2], k = 2
Output: true
Explanation:
One possible partition is to have 2 groups:
Group 1: [2, 3]
Group 2: [2, 5]
Each group contains k = 2 distinct elements, and all elements are used exactly once.

Example 3:
Input: nums = [1,5,2,3], k = 3
Output: false
Explanation:
We cannot form groups of k = 3 distinct elements using all values exactly once.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= nums.length
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
    bool partitionArray(vector<int>& nums, int k) {
        map<int, int> cnt;
        if (nums.size() % k != 0)
            return false;
        int groups = nums.size() / k;
        for (int n: nums)
            ++cnt[n];
        for (auto [k, v]: cnt) {
            if (v > groups)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
