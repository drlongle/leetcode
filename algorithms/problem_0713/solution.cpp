/*
713. Subarray Product Less Than K
Medium

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements
in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Note:
0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
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
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        vector<double> nums, prefix;
        for (auto a: A)
            nums.emplace_back(log(a));
        partial_sum(nums.begin(), nums.end(), back_inserter(prefix));
        double thres = log(k);
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            double key = thres + ((i > 0) ? prefix[i-1] : 0);
            int lo = i, hi = n - 1, bound = -1;
            while (lo <= hi) {
                int mid = (lo+hi) / 2;
                if (prefix[mid] >= key)
                    hi = mid - 1;
                else {
                    lo = mid + 1;
                    bound = mid;
                }
            }

            if (bound >= i)
                res += bound - i + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: 8
    nums = {10, 5, 2, 6}, k = 100;
    //cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

    // Output: 0
    nums = {1,2,3}, k = 0;
    //cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

    // Output: 18
    nums = {10,9,10,4,3,8,3,3,6,2,10,10,9,3}, k = 19;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}
