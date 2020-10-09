/*
898. Bitwise ORs of Subarrays
Medium

We have an array A of non-negative integers.

For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the
elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].

Return the number of possible results.  (Results that occur more than once are only counted once in the final
answer.)

Example 1:
Input: [0]
Output: 1
Explanation:
There is only one possible result: 0.

Example 2:
Input: [1,1,2]
Output: 3
Explanation:
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:
Input: [1,2,4]
Output: 6
Explanation:
The possible results are 1, 2, 3, 4, 6, and 7.

Note:
1 <= A.length <= 50000
0 <= A[i] <= 10^9
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

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> all;
        int sz = nums.size();
        vector<int> mask(sz);
        for (int i = sz-1, running = 0; i >= 0; --i) {
            running |= nums[i];
            mask[i] = running;
        }

        for (int i = 0; i < sz; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i, running = 0; j < sz; ++j) {
                running |= nums[j];
                all.insert(running);
                if ((running | mask[j]) == running)
                    break;
            }
        }

        return all.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 1
    nums = {0};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    // Output: 3
    nums = {1,1,2};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    // Output: 6
    nums = {1,2,4};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    // Output: 5
    nums = {6,12,7};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    // Output: 9
    nums =  {108,121,9,85,27};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    // Output: 22
    nums = {420,226,570,648,434,971,772,852,802,907};
    cout << sol.subarrayBitwiseORs(nums) << endl;

    return 0;
}
