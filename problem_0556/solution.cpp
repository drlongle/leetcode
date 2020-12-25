/*
556. Next Greater Element III
Medium

Given a positive integer n, find the smallest integer which has exactly the same digits existing
in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but
it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1

Constraints:
1 <= n <= 2^31 - 1
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
    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        if (nums.empty())
            return 0;
        reverse(begin(nums), end(nums));
        int sz = nums.size(), i = sz - 2;
        while (i >= 0) {
            if (nums[i] < nums[i+1])
                break;
            --i;
        }
        if (i < 0)
            return -1;
        int k = -1;
        for (int j = i + 1; j < sz; ++j) {
            if (nums[j] > nums[i] && (k == -1 || nums[j] < nums[k])) {
                k = j;
            }
        }

        swap(nums[i], nums[k]);
        sort(nums.begin() + i + 1 , nums.end());

        long long res = 0;
        for (int i = 0, sz = nums.size(); i < sz && res <= numeric_limits<int>::max(); ++i)
            res = res*10 + nums[i];
        return res <= numeric_limits<int>::max() ? res : -1;
    }
};

int main() {
    Solution sol;
    int n;

    n = 12;
    cout << sol.nextGreaterElement(n) << endl;

    n = 21;
    cout << sol.nextGreaterElement(n) << endl;

    n = 213;
    cout << sol.nextGreaterElement(n) << endl;

    n = 1234;
    cout << sol.nextGreaterElement(n) << endl;

    n = 1534;
    cout << sol.nextGreaterElement(n) << endl;

    n = 999;
    cout << sol.nextGreaterElement(n) << endl;

    // Output: 12223233
    n = 12222333;
    cout << n << " -> " << sol.nextGreaterElement(n) << endl;

    // Output: 13222344
    n = 12443322;
    cout << n << " -> " << sol.nextGreaterElement(n) << endl;

    return 0;
}
