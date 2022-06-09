/*
553. Optimal Division
Medium

You are given an integer array nums. The adjacent integers in nums will perform
the float division.

For example, for nums = [2,3,4], we will evaluate the expression "2/3/4".
However, you can add any number of parenthesis at any position to change the
priority of operations. You want to add these parentheses such the value of the
expression after the evaluation is maximum.

Return the corresponding expression that has the maximum value in string format.

Note: your expression should not contain redundant parenthesis.

Example 1:
Input: nums = [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, since they
don't influence the operation priority. So you should return "1000/(100/10/2)".
Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2

Example 2:

Input: nums = [2,3,4]
Output: "2/(3/4)"
Example 3:

Input: nums = [2]
Output: "2"


Constraints:

1 <= nums.length <= 10
2 <= nums[i] <= 1000
There is only one optimal division for the given input.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    string optimalDivision(vector<int> &nums) {
        int sz = nums.size();
        if (sz == 1)
            return to_string(nums[0]);
        if (sz == 2)
            return to_string(nums[0]) + '/' + to_string(nums[1]);
        ostringstream oss;
        oss << nums[0] << "/(";
        for (int i = 1; i < sz; ++i) {
            if (i != 1)
                oss << '/';
            oss << nums[i];
        }
        oss << ')';
        return oss.str();
    }
};

int main() {
    Solution sol;

    return 0;
}
