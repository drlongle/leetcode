/*
1296. Divide Array in Sets of K Consecutive Numbers
Medium

Given an array of integers nums and a positive integer k, find whether it's possible to divide this
array into sets of k consecutive numbers Return True if its possible otherwise return False.


Example 1:
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Example 2:
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Example 3:
Input: nums = [3,3,2,2,1,1], k = 3
Output: true

Example 4:
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length
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
    bool isPossibleDivide(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz % k)
            return false;
        map<int, int> count;
        for (int n: nums)
            ++count[n];
        
        vector<int> accu(k, 0);
        int index = 0, expected = 0, prev;
        for (auto& p: count) {
            expected -= accu[index % k];
            int diff = p.second - expected;
            if (diff < 0)
                return false;
            else {
                if (expected > 0 && prev != p.first - 1)
                    return false;
                accu[index %k] = diff;
                expected += diff;
            }
            prev = p.first;
            ++index;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: true
    nums = {1,2,3,3,4,4,5,6}, k = 4;

    // Output: true
    //nums = {3,2,1,2,3,4,3,4,5,9,10,11}, k = 3;

    // Output: true
    //nums = {3,3,2,2,1,1}, k = 3;

    // Output: false
    //nums = {1,2,3,4}, k = 3;

    // Output: false
    //nums = {1,2,3,3,4,4,5,7}, k = 4;

    // Output: false
    //nums = {1,3}, k = 2;
    
    cout << "Result: " << sol.isPossibleDivide(nums, k) << endl;
    
    return 0;
}
