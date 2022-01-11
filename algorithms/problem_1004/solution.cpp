/*
1004. Max Consecutive Ones III
Difficulty> Medium

Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.

Example 1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int longestOnes(vector<int>& nums, int K) {
        int length= 0, nsize = nums.size();
        int fast = 0, slow=0, changes = K;

        while ( fast < nsize) {
            while (fast < nsize && (nums[fast] || (!nums[fast] && changes > 0))) {
                if (!nums[fast])
                    --changes;
                ++fast;
            }

            int newlength = fast - slow;
            if (newlength > length) {
                length = newlength;
            }

            while (slow < fast && !changes) {
                if (!nums[slow])
                    ++changes;
                ++slow;
            }
            if (slow == fast && !K) {
                ++fast;
                ++slow;
            }
        }

        return length;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int K;

    nums = {1,1,1,0,0,0,1,1,1,1,0}, K = 2;

    cout << "Result: " << sol.longestOnes(nums, K) << endl;

    return 0;
}

