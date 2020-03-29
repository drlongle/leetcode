/*
462. Minimum Moves to Equal Array Elements II
Medium

Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:
Input:
[1,2,3]
Output:
2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
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
    int get_diff(vector<int>& nums, int val) {
        return accumulate(begin(nums), end(nums), 0, [val](auto sum, auto num) {return sum + abs(num - val);});
    }
    
    int minMoves2(vector<int>& nums) {
        int sz = nums.size();
        int mid = sz / 2;

        nth_element(begin(nums), begin(nums) + mid, end(nums));
        int res = get_diff(nums, nums[mid]);
        if (sz % 2 == 0) {
            nth_element(begin(nums), begin(nums) + mid - 1, end(nums));
            res = min(res, get_diff(nums, nums[mid-1]));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    // Output: 2
    nums = {1,2,3};
    cout << sol.minMoves2(nums) << endl;

    // Output: 1
    nums = {1,2};
    cout << sol.minMoves2(nums) << endl;

    // Output: 4
    nums = {1,5};
    cout << sol.minMoves2(nums) << endl;

    // Output: 14
    nums = {1,0,0,8,6};
    cout << sol.minMoves2(nums) << endl;
    
    return 0;
}
