/*
3191. Minimum Operations to Make Binary Array Elements Equal to One I
Medium

https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i

You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

Example 1:
Input: nums = [0,1,1,1,0,0]

Output: 3
Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].

Example 2:
Input: nums = [0,1,1,1]
Output: -1
Explanation:
It is impossible to make all elements equal to 1.

Constraints:
3 <= nums.length <= 10^5
0 <= nums[i] <= 1
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
    int minOperations(vector<int>& nums, size_t index = 0) {
        size_t sz = nums.size();
        if (index == sz)
            return 0;
        if (nums[index]) {
            auto r = minOperations(nums, index+1);
            if (r < 0)
                return -1;
            else
                return r;
        }
        
        if (index + 2 >= sz)
            return -1;
        nums[index+1] ^= 1;
        nums[index+2] ^= 1;
        auto r = minOperations(nums, index+1);
        if (r < 0)
            return -1;
        return 1 + r;      
    }
};

int main() {
    return 0;
}
