/*
487. Max Consecutive Ones II
Medium

Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

Example 1:
Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number
of consecutive 1s is 4.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 4

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store
all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
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

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size (), res=0, head=0, tail =0, phead = -1, ptail = -1;
        while (head < n) {
            while (head < n && !nums[head])
                ++head;
            res = max(res, 1);
            if (head == n)
                break;
            tail = head;
            while (head < n && nums[head]) {
                res = max(res, head - max(0, tail-1) + 1);
                ++head;
            }
            if (head < n)
                res = max(res, head - tail + 1);
            else
                res = max(res, head - tail);
            if (phead >= 0 && phead+1 == tail)
                res=max(res, head - ptail);
            phead = head, ptail = tail;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
