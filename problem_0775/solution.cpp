/*
775. Global and Local Inversions
Medium

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:
Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.

Example 2:
Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.

Note:
A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.
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
    int count_inversions(vector<int>& nums, int begin, int end) {
        int sz = end - begin;
        if (sz <= 1)
            return 0;
        int mid = (begin + end) / 2;
        int cnt = 0;
        cnt += count_inversions(nums, begin, mid);
        cnt += count_inversions(nums, mid, end);
        int i = begin, j = mid;
        while (i < mid && j < end) {
            if (nums[i] > nums[j]) {
                ++j;
                cnt += mid - i;
            } else
                i++;
        }

        i = begin, j = mid;
        while (i < mid && j < end) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                ++j;
            } else
                i++;
        }

        return cnt;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int sz = nums.size();
        int local_inversions = 0;
        for (int i = 1; i < sz; ++i)
            local_inversions += (nums[i] < nums[i-1]);
        int global_inversions = count_inversions(nums, 0, sz);

        return global_inversions == local_inversions;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: true
    nums = {1,0,2};
    cout << boolalpha << sol.isIdealPermutation(nums) << endl;

    // Output: false
    nums = {1,2,0};
    cout << boolalpha << sol.isIdealPermutation(nums) << endl;

    // true
    nums = {0,2,1};
    cout << boolalpha << sol.isIdealPermutation(nums) << endl;

    // false
    nums = {2,0,1};
    cout << boolalpha << sol.isIdealPermutation(nums) << endl;

    return 0;
}
