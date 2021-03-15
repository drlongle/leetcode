/*
1053. Previous Permutation With One Swap
Medium

Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest
permutation that is smaller than arr, that can be made with exactly one swap (A swap exchanges the
positions of two numbers arr[i] and arr[j]). If it cannot be done, then return the same array.

Example 1:
Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.

Example 2:
Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.

Example 3:
Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.

Example 4:
Input: arr = [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.

Constraints:
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^4
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> pos;
        pair<int, int> cand{-1, -1};
        for (int i = 0, n = arr.size(); i < n; ++i) {
            int a = arr[i];
            while (pos.size () && arr[pos.back()] <= a)
                pos.pop_back();
            if (pos.size() && (cand.first < 0 || cand.second <= pos.back()))
                cand = {i, pos.back()};
            pos.push_back(i);
            while (i + 1 < n && arr[i] == arr[i+1]) {
                pos.push_back(++i);
            }
        }
        if (cand.first >= 0)
            swap(arr[cand.first], arr[cand.second]);

        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Output: {3,1,2}
    arr = {3,2,1};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,1,5}
    arr = {1,1,5};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,7,4,6,9}
    arr = {1,9,4,6,7};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,3,1,3}
    arr = {3,1,1,3};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,9,5,7,6,18}
    arr = {1,9,5,18,6,7};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,3,1,3}
    arr = {3,1,1,3};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {2,1,2,1,1,2,1,2}
    arr = {2,1,2,1,1,2,2,1};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [5,1,3,1,3]
    arr = {5,3,1,1,3};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [1,7,4,6,9]
    arr = {1,9,4,6,7};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [2,1,2,1,1,2,1,2]
    arr = {2,1,2,1,1,2,2,1};
    arr = sol.prevPermOpt1(arr);
    copy(begin(arr), end(arr), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
