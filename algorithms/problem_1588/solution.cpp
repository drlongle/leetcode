/*
1588. Sum of All Odd Length Subarrays
Easy

Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

Example 1:
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58

Example 2:
Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.

Example 3:
Input: arr = [10,11,12]
Output: 66

Constraints:
1 <= arr.length <= 100
1 <= arr[i] <= 1000
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
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix{0};
        partial_sum(begin(arr), end(arr), back_inserter(prefix));
        int sum = 0, sz = arr.size();
        for (int i = 1; i <= sz; i +=2) {
            for (int j = i; j <= sz; ++j) {
                sum += prefix[j] - prefix[j-i];
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {1,4,2,5,3};
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    arr = {10,11,12};
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    return 0;
}
