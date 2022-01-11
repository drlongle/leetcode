/*
1679. Max Number of K-Sum Pairs
Medium

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Example 1:
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (int n: nums)
            ++table[n];
        int sum = 0;
        while (table.size()) {
            auto it1 = table.begin();
            if (it1->first * 2 == k) {
                sum += it1->second / 2;
                table.erase(it1);
                continue;
            }
            auto it2 = table.find(k - it1->first);
            if (it2 == table.end())
                table.erase(it1);
            else {
                int c = min(it1->second, it2->second);
                sum += c;
                it1->second -= c;
                it2->second -= c;
                if (it1->second == 0)
                    table.erase(it1);
                if (it2->second == 0)
                    table.erase(it2);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    return 0;
}
