/*
1392. Longest Happy Prefix
Hard

A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s. Return the longest happy prefix of s .
Return an empty string if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Example 3:
Input: s = "leetcodeleet"
Output: "leet"

Example 4:
Input: s = "a"
Output: ""

Constraints:
1 <= s.length <= 10^5
s contains only lowercase English letters.
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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string_view>
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
    static constexpr int mod_const = 1000000007;
    string longestPrefix(string s) {
        int sz = s.size();
        const char* ptr = s.c_str();
        long long h1 = 0, h2 = 0, len = 0, mult = 1;
        for (int i = 0, j = sz-1; i < sz - 1; ++i, --j) {
            h1 = (h1 * 10 + (s[i] - 'a')) % mod_const;
            h2 = ((s[j] - 'a') * mult + h2) % mod_const;
            if (h1 == h2) {
                string_view sv1(ptr, i+1);
                string_view sv2(ptr + j, i+1);
                if (sv1 == sv2)
                    len = i + 1;
            }
            mult = (mult * 10) % mod_const;
        }
        return s.substr(0, len);
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "l"
    s = "level";
    cout << sol.longestPrefix(s) << endl;

    // Output: "abab"
    s = "ababab";
    cout << sol.longestPrefix(s) << endl;
    
    // Output: "leet"
    s = "leetcodeleet";
    cout << sol.longestPrefix(s) << endl;
    
    // Output: ""
    s = "a";
    cout << sol.longestPrefix(s) << endl;

    s = "aabccbbbaccccccaabcc";
    cout << sol.longestPrefix(s) << endl;
    
    return 0;
}
