/*
1562. Find Latest Group of Size M
Medium

Given an array arr that represents a permutation of numbers from 1 to n. You have
a binary string of size n that initially has all its bits set to zero.

At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i]
is set to 1. You are given an integer m and you need to find the latest step at which there exists a group of ones
of length m. A group of ones is a contiguous substring of 1s such that it cannot be extended in either direction.

Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.

Example 1:
Input: arr = [3,5,1,2,4], m = 1
Output: 4
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "00101", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "11101", groups: ["111", "1"]
Step 5: "11111", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.

Example 2:
Input: arr = [3,1,5,4,2], m = 2
Output: -1
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "10100", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "10111", groups: ["1", "111"]
Step 5: "11111", groups: ["11111"]
No group of size 2 exists during any step.

Example 3:
Input: arr = [1], m = 1
Output: 1

Example 4:
Input: arr = [2,1], m = 2
Output: 2

Constraints:
n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= n
All integers in arr are distinct.
1 <= m <= arr.length
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
    struct Interval {
        Interval(int s, int e, int v): start(s), end(e), val(v) {}
        int start, end, val;
    };
    int findLatestStep(vector<int>& arr, int m) {
        map<int, Interval> lookup;
        int n = 0;
        int sz = arr.size();
        int res = -1, cnt = 0;
        for (int index = 0; index < sz; ++index) {
            int i = arr[index];
            if (i > n) {
                lookup.emplace(i, Interval(n+1, i, 0));
                n = i;
            }
            bool check_front = true, check_back = false;
            auto it = lookup.lower_bound(i);
            if (it->second.val)
                continue;
            int start = it->second.start;
            int end = it->second.end;
            if (i + 1 <= end)
                it->second.start = i+1;
            else {
                lookup.erase(it);
                check_back = true;
            }
            if (start <= i-1) {
                lookup.emplace(i - 1, Interval(start, i - 1, 0));
                check_front = false;
            }
            lookup.emplace(i, Interval(i, i, 1));
            cnt += (m == 1);
            start = i;
            end = i;
            if (check_front && start > 1) {
                auto it1 = lookup.lower_bound(start -1);
                auto it2 = lookup.lower_bound(start);
                if (it1 != lookup.end() && it2 != lookup.end() && it1->second.val && it2->second.val) {
                    if (it1->second.end - it1->second.start + 1 == m)
                        --cnt;
                    if (it2->second.end - it2->second.start + 1 == m)
                        --cnt;
                    start = it2->second.start = it1->second.start;
                    if (it2->second.end - it2->second.start + 1 == m)
                        ++cnt;
                    lookup.erase(it1);
                }
            }
            if (check_back && end < n) {
                auto it1 = lookup.lower_bound(end);
                auto it2 = lookup.lower_bound(end + 1);
                if (it1 != lookup.end() && it2 != lookup.end() && it1->second.val && it2->second.val) {
                    if (it1->second.end - it1->second.start + 1 == m)
                        --cnt;
                    if (it2->second.end - it2->second.start + 1 == m)
                        --cnt;
                    end = it2->second.end;
                    it2->second.start = it1->second.start;
                    if (it2->second.end - it2->second.start + 1 == m)
                        ++cnt;
                    lookup.erase(it1);
                }
            }

            if (cnt > 0)
                res = index + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int m;

    // Output: 4
    arr = {3,5,1,2,4}, m = 1;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: -1
    arr = {3,1,5,4,2}, m = 2;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 1
    arr = {1}, m = 1;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 2
    arr = {2,1}, m = 2;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 9
    arr = {3,2,5,6,10,8,9,4,1,7}, m = 3;
    cout << sol.findLatestStep(arr, m) << endl;

    return 0;
}
