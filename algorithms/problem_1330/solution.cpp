/*
1330. Reverse Subarray To Maximize Array Value
Hard

You are given an integer array nums. The value of this array is defined as the sum of |nums[i]-nums[i+1]| for all 0 <= i < nums.length-1.

You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.

Find maximum possible value of the final array.

Example 1:
Input: nums = [2,3,1,5,4]
Output: 10
Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.

Example 2:
Input: nums = [2,4,9,24,2,1,10]
Output: 68

Constraints:
1 <= nums.length <= 3*10^4
-10^5 <= nums[i] <= 10^5
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

/*
total calculate the total sum of |A[i] - A[i+1]|.
res record the value the we can improve.

Assume the current pair is (a,b) = (A[i], A[i+1]).

If we reverse all element from A[0] to A[i],
we will improve abs(A[0] - b) - abs(a - b)

If we reverse all element from A[i+1] to A[n-1],
we will improve abs(A[n - 1] - a) - abs(a - b)

As we iterate the whole array,
We also record the maximum pair and the minimum pair.
We can break these two pair and reverse all element in the middle.
This will improve (max2 - min2) * 2
*/

class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        int total = 0, res = 0, min2 = 123456, max2 = -123456, n = A.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = A[i], b = A[i + 1];
            total += abs(a - b);
            res = max(res, abs(A[0] - b) - abs(a - b));
            res = max(res, abs(A[n - 1] - a) - abs(a - b));
            min2 = min(min2, max(a, b));
            max2 = max(max2, min(a, b));
        }
        return total + max(res, (max2 - min2) * 2);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 10
    nums = {2,3,1,5,4};

    // Output: 68
    //nums = {2,4,9,24,2,1,10};

    cout << "Result: " << sol.maxValueAfterReverse(nums) << endl;
        
    return 0;
}
