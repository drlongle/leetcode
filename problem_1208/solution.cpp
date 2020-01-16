/*
1208. Get Equal Substrings Within Budget
Medium

You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Example 1:
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

Example 2:
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.

Example 3:
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.

Constraints:
1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.
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

    int sz, max_cost;
    
    bool findSubstring(string& s, string& t, int len) {
        int i, cost = 0;
        for (i = 0; i < len; ++i) {
            cost += abs(s[i] - t[i]);
        }
        if (cost <= max_cost)
            return true;
        for (; i < sz; ++i) {
            cost += abs(s[i] - t[i]);
            cost -= abs(s[i-len] - t[i-len]);
            if (cost <= max_cost)
                return true;
        }

        return false;
    }
    
    int equalSubstring(string s, string t, int maxCost) {
        sz = s.size(), max_cost = maxCost;
        int low = 0, high = sz, res = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (findSubstring(s, t, mid)) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s, t;
    int maxCost;

    // Output: 3
    s = "abcd", t = "bcdf", maxCost = 3;

    // Output: 1
    s = "abcd", t = "cdef", maxCost = 3;

    // Output: 1
    s = "abcd", t = "acde", maxCost = 0;

    // Output: 2
    s = "krrgw", t = "zjxss", maxCost = 19;

    // Output: 5
    s = "ujteygggjwxnfl", t = "nstsenrzttikoy", maxCost = 43;

    // Output: 18
    s = "tyiraojpcfuttwblehv", t = "stbtakjkampohttraky", maxCost = 119;
    
    cout << "Result: " << sol.equalSubstring(s, t, maxCost) << endl;

    return 0;
}
