/*
1520. Maximum Number of Non-Overlapping Substrings
Medium

Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions
with the same number of substrings, return the one with minimum total length. It can be shown that
there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

Example 1:
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1.
If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings.
Notice also, that it's not optimal to choose "ef" since it can be split into two.
Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

Example 2:
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.

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
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
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
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26);
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            int index = s[i] - 'a';
            if (first[index] < 0)
                first[index] = i;
            last[index] = i;
        }

        vector<char> sorted_char;
        for (int i = 0; i < 26; ++i) {
            if (first[i] >= 0)
                sorted_char.emplace_back('a' + i);
        }

        unordered_map<char, vector<int>> cache;

        auto expand = [&] (char ch) {
            auto it = cache.find(ch);
            if (it != cache.end())
                return it->second;
            int index = ch - 'a';
            int start = first[index];
            int end = last[index];
            for (int i = first[index]; i < end; ++i) {
                if (first[s[i]-'a'] < start) {
                    int j = start;
                    start = first[s[i]-'a'];
                    for (; j >= start; --j) {
                        start = min(start, first[s[j]-'a']);
                        end = max(end, last[s[j]-'a']);
                    }
                }
                end = max(end, last[s[i]-'a']);
            }
            return cache[ch] = vector<int>{start, end};
        };
        auto lambda = [&] (int i, int j) {
            auto xi = expand(i)[1];
            auto xj = expand(j)[1];
            return xi < xj || (xi == xj && first[i-'a'] > first[j-'a']);
        };

        sort(begin(sorted_char), end(sorted_char), lambda);
        vector<string> res;
        int pos = 0, index = 0, ssz = sorted_char.size();
        while (pos < sz) {
            while (index < ssz) {
                auto x = expand(sorted_char[index]);
                if (x[0] >= pos)
                    break;
                else
                    ++index;
            }
            if (index == ssz)
                break;
            auto x = expand(sorted_char[index]);
            res.emplace_back(s.substr(x[0], x[1]-x[0]+1));
            pos = x[1] + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string> res;

    // Output: ["e","f","ccc"]
    s = "adefaddaccc";
    res = sol.maxNumOfSubstrings(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: ["d","bb","cc"]
    s = "abbaccd";
    res = sol.maxNumOfSubstrings(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: "abab"
    s = "abab";
    res = sol.maxNumOfSubstrings(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    s = "dabddcdc";
    res = sol.maxNumOfSubstrings(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: ["cabcccbaa"]
    s = "cabcccbaa";
    res = sol.maxNumOfSubstrings(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    return 0;
}
