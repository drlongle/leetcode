/*
1524. Number of Sub-arrays With Odd Sum
Medium

Given an array of integers arr. Return the number of sub-arrays with odd sum.

As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:
Input: arr = [1,3,5]
Output: 4
Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:
Input: arr = [2,4,6]
Output: 0
Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:
Input: arr = [1,2,3,4,5,6,7]
Output: 16

Example 4:
Input: arr = [100,100,99,99]
Output: 4

Example 5:
Input: arr = [7]
Output: 1

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 100
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
    int numOfSubarrays(vector<int>& arr) {
        array<int, 2> cnt{1, 0};
        int sum = 0, res = 0;;
        for (int a: arr) {
            sum = (sum + a) % 2;
            res =  (res + cnt[1 - sum]) % 1000000007;
            ++cnt[sum];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: 4
    arr = {1,3,5};
    cout << sol.numOfSubarrays(arr) << endl;

    // Output: 0
    arr = {2,4,6};
    cout << sol.numOfSubarrays(arr) << endl;

    // Output: 16
    arr = {1,2,3,4,5,6,7};
    cout << sol.numOfSubarrays(arr) << endl;

    // Output: 4
    arr = {100,100,99,99};
    cout << sol.numOfSubarrays(arr) << endl;

    // Output: 1
    arr = {7};
    cout << sol.numOfSubarrays(arr) << endl;

    return 0;
}
