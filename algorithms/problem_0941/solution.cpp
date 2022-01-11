/*
941. Valid Mountain Array
Easy

Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Example 1:
Input: [2,1]
Output: false

Example 2:
Input: [3,5,5]
Output: false

Example 3:
Input: [0,3,2,1]
Output: true

Note:
0 <= A.length <= 10000
0 <= A[i] <= 10000 
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
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        int up = -1, down = -1;
        for (int i = 0; i < n-1; ++i) {
            int diff = nums[i] - nums[i+1];
            if (diff == 0)
                return false;
            if (diff > 0)
                break;
            else
                up = i;
        }
        for (int i = n-1; i > 0; --i) {
            int diff = nums[i] - nums[i-1];
            if (diff == 0)
                return false;
            if (diff > 0)
                break;
            else
                down = i;
        }
        
        return (up >= 0 && down >= 0 && up + 2 == down);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: true
    nums = {1,3,2};
    cout << boolalpha << sol.validMountainArray(nums) << endl;

    // Output: false
    nums = {2,1};
    cout << boolalpha << sol.validMountainArray(nums) << endl;
    
    // Output: false
    nums = {3,5,5};
    cout << boolalpha << sol.validMountainArray(nums) << endl;
    
    // Output: true
    nums = {0,3,2,1};
    cout << boolalpha << sol.validMountainArray(nums) << endl;
    
    // Output: true
    nums = {0,2,3,4,5,2,1, 0};
    cout << boolalpha << sol.validMountainArray(nums) << endl;

    // Output: false
    nums = {0,2,3,3,5,2,1, 0};
    cout << boolalpha << sol.validMountainArray(nums) << endl;

    return 0;
}
