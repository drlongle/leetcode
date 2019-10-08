/*
1200. Minimum Absolute Difference
Easy

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute
difference of any two elements.  Return a list of pairs in ascending order(with respect to pairs),
each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Example 2:
Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Example 3:
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int mindiff = numeric_limits<int>::max();
        for (size_t i = 1; i < arr.size(); ++i) {
            mindiff = min(mindiff, arr[i] - arr[i-1]);
        }
        vector<vector<int>> res;
        for (size_t i = 1; i < arr.size(); ++i) {
            if (mindiff == arr[i] - arr[i-1])
                res.emplace_back(vector<int>{arr[i-1], arr[i]});
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: [[1,2],[2,3],[3,4]]
    arr = {4,2,1,3};

    // Output: [[1,3]]
    arr = {1,3,6,10,15};

    // Output: [[-14,-10],[19,23],[23,27]]
    arr = {3,8,-10,23,19,-4,-14,27};

    auto res = sol.minimumAbsDifference(arr);
    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
