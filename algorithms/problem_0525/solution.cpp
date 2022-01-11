/*
525. Contiguous Array
Medium

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> lookup;
        int sum = 0, res = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            sum += (nums[i] == 0) ? 1 : -1;
            if (sum == 0)
                res = max(res, i+1);
            auto it = lookup.find(sum);
            if (it == lookup.end())
                lookup[sum] = i;
            else
                res = max(res, i - it->second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
