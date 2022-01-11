/*
949. Largest Time for Given Digits
Easy

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59. Starting from 00:00, a time is
larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

Example 1:
Input: [1,2,3,4]
Output: "23:41"

Example 2:
Input: [5,5,5,5]
Output: ""

Note:
A.length == 4
0 <= A[i] <= 9
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
    string largestTimeFromDigits(vector<int>& nums) {
        vector<int> cnt(10, 0);
        for (int num: nums)
            ++cnt[num];
        ostringstream oss;
        int digits = 0;
        for (int i = accumulate(cnt.begin() + 6, cnt.end(), 0) >= 2 ? 1 : 2; i >= 0 && digits < 1; --i) {
            while (cnt[i] > 0 && digits < 1) {
                oss << i;
                ++digits;
                --cnt[i];
            }
        }
        if (digits < 1)
            return "";

        for (int i = oss.str() == "2" ? 3 : 9; i >= 0 && digits < 2; --i) {
            while (cnt[i] > 0 && digits < 2) {
                oss << i;
                ++digits;
                --cnt[i];
            }
        }
        if (digits < 2)
            return "";

        oss << ':';
        for (int i = 5; i >= 0 && digits < 3; --i) {
            if (cnt[i] > 0) {
                oss << i;
                ++digits;
                --cnt[i];
            }
        }
        if (digits < 3)
            return "";
        auto it = find(cnt.begin(), cnt.end(), 1);
        oss << (it - cnt.begin());

        return oss.str();
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: "23:41"
    nums = {1,2,3,4};
    cout << sol.largestTimeFromDigits(nums) << endl;

    // Output: ""
    nums = {5,5,5,5};
    cout << sol.largestTimeFromDigits(nums) << endl;

    // Output: ""
    nums = {0,0,0,0};
    cout << sol.largestTimeFromDigits(nums) << endl;

    // Output: "04:00"
    nums = {0,4,0,0};
    cout << sol.largestTimeFromDigits(nums) << endl;

    nums = {1,9,6,0};
    cout << sol.largestTimeFromDigits(nums) << endl;

    nums = {2,0,6,6};
    cout << sol.largestTimeFromDigits(nums) << endl;

    return 0;
}
