/*
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
Difficulty: Medium

Given an array of integers arr and an integer target.
You have to find two non-overlapping sub-arrays of arr each with sum equal target. There can be multiple
answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays,
or return -1 if you cannot find such two sub-arrays.

Example 1:
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

Example 2:
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]),
but we will choose the first and third sub-arrays as the sum of their lengths is 2.

Example 3:
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.

Example 4:
Input: arr = [5,5,4,4,5], target = 3
Output: -1
Explanation: We cannot find a sub-array of sum = 3.

Example 5:
Input: arr = [3,1,1,1,5,1,2,1], target = 3
Output: 3
Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an answer because they overlap.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 1000
1 <= target <= 10^8
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

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int res = numeric_limits<int>::max();
        unordered_map<int, int> prefix{{0,-1}};
        vector<pair<int, int>> dp;
        int sum = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            prefix[sum] = i;
            int index = sum - target;
            auto it = prefix.find(index);
            if (it != prefix.end()) {
                for (auto& p: dp) {
                    if (p.second <= it->second) {
                        auto dist = (i - it->second) + (p.second - p.first);
                        res = min(res, dist);
                    }
                }

                if (dp.empty() || i - it->second < dp.back().second - dp.back().first)
                    dp.emplace_back(it->second, i);
            }
        }

        return res != numeric_limits<int>::max() ? res : -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int target;

    // Output: 2
    arr = {3,2,2,4,3}, target = 3;
    cout << sol.minSumOfLengths(arr, target) << endl;
    
    // Output: 2
    arr = {7,3,4,7}, target = 7;
    cout << sol.minSumOfLengths(arr, target) << endl;
    
    // Output: -1
    arr = {4,3,2,6,2,3,4}, target = 6;
    cout << sol.minSumOfLengths(arr, target) << endl;
        
    // Output: -1
    arr = {5,5,4,4,5}, target = 3;
    cout << sol.minSumOfLengths(arr, target) << endl;
    
    // Output: 3
    arr = {3,1,1,1,5,1,2,1}, target = 3;
    cout << sol.minSumOfLengths(arr, target) << endl;

    // Output : -1
    arr = {1,6,1}, target = 7;
    cout << sol.minSumOfLengths(arr, target) << endl;
    
    // Output: 6
    arr = {1,1,1,2,2,2,4,4}, target = 6;
    cout << sol.minSumOfLengths(arr, target) << endl;

    return 0;
}
