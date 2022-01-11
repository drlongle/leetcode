/*
1283. Find the Smallest Divisor Given a Threshold
Medium

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer. 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:
Input: nums = [2,3,5,7,11], threshold = 11
Output: 3

Example 3:
Input: nums = [19], threshold = 5
Output: 4

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
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
    bool check(vector<int>& nums, int threshold, int divisor) {
        auto lambda = [divisor] (int a, int b) { return a + ceil((double)b/divisor);};
        int sum  = accumulate(begin(nums), end(nums), 0, lambda);
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = 1000000;
        int low = 1, high = 1000000;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, threshold, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
