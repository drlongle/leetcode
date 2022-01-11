/*
1131. Maximum of Absolute Value Expression
Medium

Given two arrays of integers with equal lengths, return the maximum value of:
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length.

Example 1:
Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13

Example 2:
Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

    int max_diff(vector<int>& nums) {
        auto mm_it = minmax_element(begin(nums), end(nums));

        return *(mm_it.second) - *(mm_it.first);
    }

    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> num1(n), num2(n), num3(n), num4(n);
        for (int i = 0; i < n; ++i) {
            num1[i] = arr1[i] + arr2[i] + i;
            num2[i] = arr1[i] + arr2[i] - i;
            num3[i] = arr1[i] - arr2[i] + i;
            num4[i] = arr1[i] - arr2[i] - i;
        }

        return max({max_diff(num1), max_diff(num2), max_diff(num3), max_diff(num4)});
    }
};

int main() {
    Solution sol;

    vector<int> arr1, arr2;

    // Expected: 13
    arr1 = {1,2,3,4}, arr2 = {-1,4,5,6};

    // Expected: 20
    //arr1 = {1,-2,-5,0,10}, arr2 = {0,-2,-1,-7,-4};

    cout << "Result: " << sol.maxAbsValExpr(arr1, arr2) << endl;

    return 0;
}

