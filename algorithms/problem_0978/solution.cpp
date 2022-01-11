/*
978. Longest Turbulent Subarray
Difficulty: Medium

A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each
adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

Example 1:
Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])

Example 2:
Input: [4,8,12,16]
Output: 2

Example 3:
Input: [100]
Output: 1
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int nsize = nums.size();
        int start = 0, res = 0, end;
        while (start < nsize) {
            end = start+1;
            if (end == nsize)
                break;
            bool up = (nums[end] > nums[start]);
            while (true) {
                if (end == nsize) {
                    break;
                }
                if ((up && nums[end] <= nums[end-1])
                        || (!up && nums[end] >= nums[end-1])) {
                    --end;
                    break;
                }
                up ^= true;
                ++end;
            }
            res = max(res, min(nsize-1, end) - start + 1);
            start = max(start+1, end);
        }
        return max(res, end - start);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;
    
    // Expected: 5
    nums = {9,4,2,10,7,8,8,1,9};
    
    // Expected: 2
    //nums = {4,8,12,16};
    
    // Expected: 1
    //nums = {100};
    
    cout << "Result: " << sol.maxTurbulenceSize(nums) << endl;

    return 0;
}
