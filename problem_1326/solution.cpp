/*
1326. Minimum Number of Taps to Open to Water a Garden
Hard

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

Example 3:
Input: n = 7, ranges = [1,2,1,0,2,1,0,1]
Output: 3

Example 4:
Input: n = 8, ranges = [4,0,0,0,0,0,0,0,4]
Output: 2

Example 5:
Input: n = 8, ranges = [4,0,0,0,4,0,0,0,4]
Output: 1

Constraints:
1 <= n <= 10^4
ranges.length == n + 1
0 <= ranges[i] <= 100
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
    int minTaps(int n, vector<int>& ranges) {
        map<int, int> coverage;
        for (int i = 0; i <= n; ++i) {
            if (ranges[i] == 0)
                continue;
            int key = i - ranges[i];
            int val = i + ranges[i];
            auto it = coverage.find(key);
            if (it == coverage.end() || it->second < val)
                coverage[key] = val;
        }
        if (coverage.empty())
            return -1;
        
        int curr = 0, res = 0;
        auto it = coverage.begin();
        while (curr < n) {
            int next = curr;
            while (it != coverage.end() && it->first <= curr) {
                next = max(next, it->second);
                ++it;
            }
            if (next == curr)
                return -1;
            ++res;
            curr = next;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> ranges;
    int n;

    // Output: 1
    n = 5, ranges = {3,4,1,1,0,0};

    // Output: -1
    n = 3, ranges = {0,0,0,0};

    // Output: 3
    n = 7, ranges = {1,2,1,0,2,1,0,1};

    // Output: 2
    n = 8, ranges = {4,0,0,0,0,0,0,0,4};

    // ???
    // Output: 1;
    n = 8, ranges = {4,0,0,0,4,0,0,0,4};

    // Output: 3
    n = 17, ranges = {0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1};

    // Output: 6
    n = 35, ranges = {1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2};
    
    cout << "Result: " << sol.minTaps(n, ranges) << endl;
    
    return 0;
}
