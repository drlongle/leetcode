/*
912. Sort an Array
Medium

Given an array of integers nums, sort the array in ascending order.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

Constraints:
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
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
    void sort(vector<int>& nums, int begin, int end) {
        if (begin >= end)
            return;
        int mid = (begin + end) / 2;
        sort(nums, begin, mid);
        sort(nums, mid+1, end);
        int sz = end-begin+1;
        vector<int> arr(sz);
        for (int k = 0, i = begin, j = mid+1; k < sz; ++k) {
            if (j > end || (nums[j] > nums[i] && i <= mid))
                arr[k] = nums[i++];
            else
                arr[k] = nums[j++];
        }

        copy(arr.begin(), arr.end(), nums.begin() + begin);
    }
    vector<int> sortArray(vector<int>& nums) {
        //sort(begin(nums), end(nums));
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;

    // Output: {1,2,3,5}
    nums = {5,2,3,1};
    res = sol.sortArray(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,0,1,1,2,5}
    nums = {5,1,1,2,0,0};
    res = sol.sortArray(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    nums = {-4,0,7,4,9,-5,-1,0,-7,-1};
    res = sol.sortArray(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
