/*
658. Find K Closest Elements
Medium

Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result
should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lambda = [x] (int a, int b) {
            int da = abs(x-a), db = abs(x-b);
            return da < db || (da == db && a < b);
        };

        sort(begin(arr), end(arr), lambda);
        arr.resize(k);
        sort(begin(arr), end(arr));

        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int k, x;

    // Output: [1,2,3,4]
    arr = {1,2,3,4,5}, k = 4, x = 3;
    arr = sol.findClosestElements(arr, k, x);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [1,2,3,4]
    arr = {1,2,3,4,5}, k = 4, x = -1;
    arr = sol.findClosestElements(arr, k, x);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
