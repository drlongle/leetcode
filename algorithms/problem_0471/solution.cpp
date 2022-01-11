/*
471. Encode String with Shortest Length
Hard

Given a string s, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets
is being repeated exactly k times. k should be a positive integer.

If an encoding process does not make the string shorter, then do not encode it. If there are
several solutions, return any of them.

Example 1:
Input: s = "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.

Example 2:
Input: s = "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.

Example 3:
Input: s = "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".

Example 4:
Input: s = "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".

Example 5:
Input: s = "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".

Constraints:
1 <= s.length <= 150
s consists of only lowercase English letters.

https://leetcode.com/problems/encode-string-with-shortest-length/
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
    string encode(string &s, int i, int j) {
        if (i > j)
            return "";
        string& res = dp[i][j];
        if (!res.empty())
            return res;
        int len = j - i + 1;
        res = s.substr(i, len);
        if (len <= 3)
            return res;
        for (int l = 1; l <= len / 2; ++l) {
            auto divmod = std::div(len, l);
            if (divmod.rem != 0)
                continue;
            string t = s.substr(i, l);
            bool match = true;
            for (int h = 1; h < divmod.quot && match; ++h)
                match = (s.substr(i + h * l, l) == t);
            if (match) {
                string v = to_string(divmod.quot) +'[' + encode(s, i, i + l - 1) +']';
                if (v.size() < res.size())
                    res = v;
                break;
            }
        }

        for (int k = i; k <= j; ++k) {
            string a = encode(s, i, k);
            string b = encode(s, k + 1, j);
            if (a.size() + b.size() < res.size())
                res = a + b;
        }

        return res;
    }

    vector<vector<string>> dp;

    string encode(string s) {
        int sz = s.size();
        dp.resize(sz, vector<string>(sz));
        return encode(s, 0, sz - 1);
    }
};

int main() {
    string s;

    // Output: "aaa"
    {
        Solution sol;
        s = "aaa";
        cout << s << " -> " << sol.encode(s) << endl;
    }

    // Output: "5[a]"
    s = "aaaaa";
    {
        Solution sol;
        cout << s << " -> " << sol.encode(s) << endl;
    }

    // Output: "10[a]"
    s = "aaaaaaaaaa";
    {
        Solution sol;
        cout << s << " -> " << sol.encode(s) << endl;
    }

    // Output: "2[aabc]d"
    s = "aabcaabcd";
    {
        Solution sol;
        cout << s << " -> " << sol.encode(s) << endl;
    }

    // Output: "2[2[abbb]c]"
    s = "abbbabbbcabbbabbbc";
    {
        Solution sol;
        cout << s << " -> " << sol.encode(s) << endl;
    }

    return 0;
}
