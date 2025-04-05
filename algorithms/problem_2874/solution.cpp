/*
2874. Maximum Value of an Ordered Triplet II
Medium

You are given a 0-indexed integer array nums.
Return the maximum value over all triplets of indices (i, j, k) such that i < j < k.
If all such triplets have a negative value, return 0.
The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

Example 1:
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77.

Example 2:
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.

Example 3:
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3.
Hence, the answer would be 0.

Constraints:
3 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
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
    long long maximumTripletValue(vector<int>& nums) {
        if (ranges::is_sorted(nums))
            return 0;

        int sz = nums.size();
        deque<int> cand_i;
        vector<int> cand_k(sz);
        for (int i = sz -1, m  = 0 ; i >= 0; --i) {
            int num_i = nums[i];
            while (!cand_i.empty() && nums[cand_i.front()] <= num_i) {
                cand_i.pop_front();
            }
            cand_i.push_front(i);
            cand_k[i] = m;
            m = max(m, nums[i]);
        }

        deque<int> cand_j;

        for (int n = cand_i.size(), i = n-1; i >= 0; --i) {
            int low_j = cand_i[i];
            int high_j = (i < n - 1) ? cand_i[i + 1] : sz - 1;
            for (int j = high_j; j > low_j; --j) {
                int num_j = nums[j];
                while (!cand_j.empty() && nums[cand_j.front()] >= num_j && cand_j.front() <= high_j) {
                    cand_j.pop_front();
                }
                cand_j.push_front(j);
            }
        }

        long long res = 0;
        size_t j_index = 0;
        for (int i: cand_i) {
            int num_i = nums[i];
            while (j_index < cand_j.size() && cand_j[j_index] <= i) {
                ++j_index;
            }

            for (size_t j = j_index; j < cand_j.size(); ++j) {
                int jj = cand_j[j];
                int num_j = nums[jj];
                if (num_j < num_i)
                    res = std::max(res, ((long long) (num_i - num_j)) * cand_k[jj]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 77
    nums = {12,6,1,2,7};
    cout << sol.maximumTripletValue(nums) << endl;

    // Output: 133
    nums = {1,10,3,4,19};
    cout << sol.maximumTripletValue(nums) << endl;

    // Output: 0
    nums = {1,2,3};
    cout << sol.maximumTripletValue(nums) << endl;

    // Output: 266
    nums = {8,6,3,13,2,12,19,5,19,6,10,11,9};
    cout << sol.maximumTripletValue(nums) << endl;

    // Output: 260
    nums = {13,4,3,19,16,14,17,6,20,6,16,4};
    cout << sol.maximumTripletValue(nums) << endl;

    return 0;
}
