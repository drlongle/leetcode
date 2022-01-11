/*
1187. Make Array Strictly Increasing
Hard

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

Example 1:
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:
Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
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
For any operation, we need to pick the smallest possible element from the second array. So, we can start by sorting the second array.

Solution
Run the search with two branches:

Keep the current element (if increasing),
add an operation.
Return the minimum of these branches. For memoisation, use indexes of the first and second arrays.

Note that we need to advance the index of the second array first, based on the previous value (prev).
 */

class Solution {
public:
    short dp[2001][2001] = {};
    int dfs(vector<int>& a1, vector<int>& a2, int i1, int i2, int prev) {
        if (i1 >= a1.size()) return 1; // to mark the asnwer - 'll subtract it later.
        i2 = upper_bound(begin(a2) + i2, end(a2), prev) - begin(a2);
        if (dp[i1][i2]) return dp[i1][i2];
        auto r1 = i2 < a2.size() ? 1 + dfs(a1, a2, i1 + 1, i2, a2[i2]) : a2.size() + 1;
        auto r2 = prev < a1[i1] ? dfs(a1, a2, i1 + 1, i2, a1[i1]) : a2.size() + 1;
        return dp[i1][i2] = min(r1, r2);
    }
    
    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        sort(begin(a2), end(a2));
        auto res = dfs(a1, a2, 0, 0, INT_MIN);
        return res > a2.size() ? -1 : res - 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr1, arr2;

    // Output: 1
    arr1 = {1,5,3,6,7}, arr2 = {1,3,2,4};

    // Output: 2
    //arr1 = {1,5,3,6,7}, arr2 = {4,3,1};
    
    // Output: -1
    //arr1 = {1,5,3,6,7}, arr2 = {1,6,3,3};

    // Output: 5
    //arr1 = {0,11,6,1,4,3}, arr2 = {5,4,11,10,1,0};

    // Output: 8
    //arr1 = {5,16,19,2,1,12,7,14,5,16};
    //arr2 = {6,17,4,3,6,13,4,3,18,17,16,7,14,1,16};

    // Output: 9
    //arr1 = {19,18,7,4,11,8,3,10,5,8,13};
    //arr2 = {13,16,9,14,3,12,15,4,21,18,1,8,17,0,3,18};
    
    cout << "Result: " << sol.makeArrayIncreasing(arr1, arr2) << endl;
    
    return 0;
}
