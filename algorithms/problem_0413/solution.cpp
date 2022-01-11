/*
413. Arithmetic Slices
Medium

A sequence of number is called arithmetic if it consists of at least three elements
and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7


A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

Example:
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
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

    int count_seqs(int elems) {
        int res = 0;
        for (int len = 3; len <= elems; ++len) {
            res += elems - len + 1;
        }
        return res;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        if (nums.size() <= 2)
            return 0;
        int diff = nums[1] - nums[0];
        int prev = 0, curr = 2, nsize = nums.size();
        for (; curr < nsize; ++curr) {
            int d = nums[curr] - nums[curr-1];
            if (d != diff) {
                res += count_seqs(curr - prev);
                diff = d;
                prev = curr - 1;
            }
        }
        
        res += count_seqs(nsize - prev);
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Expected: 3
    nums = {1,2,3,4};
    nums = {7, 7, 7, 7};
    nums = {3, -1, -5, -9};
    
    // Expected: 6
    nums = {1, 3, 5, 7, 9};
    
    // Expected: 6
    nums = {1, 3, 5, 7, 9, 2};
    
    // Expected: 7
    nums = {1, 3, 5, 7, 9, 2, -5};
    
    // Expected: 9
    //nums = {1, 3, 5, 7, 9, 2, 1, 0, -1};
    
    cout << "Result: " << sol.numberOfArithmeticSlices(nums) << endl;
    
    return 0;
}
