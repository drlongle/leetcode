/*
1403. Minimum Subsequence in Non-Increasing Order

Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

Example 1:
Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 

Example 2:
Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  

Example 3:
Input: nums = [6]
Output: [6]

Constraints:
1 <= nums.length <= 500
1 <= nums[i] <= 100
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());
        auto total = accumulate(begin(nums), end(nums), 0);
        vector<int> res;
        int sum = 0;
        for (int i = 0, sz = nums.size(); i < sz && sum <= total/2; ++i) {
            res.push_back(nums[i]);
            sum += nums[i];
            
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;

    nums = {4,3,10,9,8};
    res = sol.minSubsequence(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    nums = {4,4,7,6,7};
    res = sol.minSubsequence(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    nums = {6};
    res = sol.minSubsequence(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
