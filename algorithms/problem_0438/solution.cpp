/*
438. Find All Anagrams in a String

    User Tried: 159
    Total Submissions: 185
    Difficulty: Easy

Given a string s and a non-empty string p, find all the start indices of p's
anagrams in s. Strings consists of lowercase English letters only and the
length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> expected, running;

        for (char c: p)
            ++expected[c];

        int psize = static_cast<int>(p.size());
        int ssize = static_cast<int>(s.size());
        int count = 0;
        for (int i = 0; i < ssize; ++i) {
            char c = s[i];
            if (expected.find(c) == expected.end()) {
                running.clear();
                count = 0;
                continue;
            }
            if (++running[c] == expected[c]) {
                if (++count == static_cast<int>(expected.size()))
                    res.emplace_back(i-psize+1);
            }
            if (i >= psize-1) {
                c = s[i-psize+1];
                if (expected.find(c) != expected.end() &&
                    running.find(c) != running.end() && count > 0) {
                    if (running[c]-- == expected[c])
                        --count;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> res;
    string s, p;

    // Expected: [0, 6]
    s = "cbaebabacd";
    p = "abc";

    // Expected: [0, 1, 2]
    s = "abab";
    p = "ab";

    res = sol.findAnagrams(s, p);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}

