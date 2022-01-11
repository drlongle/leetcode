/*
76. Minimum Window Substring  
Total Accepted: 59208 Total Submissions: 278010 Difficulty: Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/

#include <algorithm>
#include <cassert>
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
    string minWindow(string s, string t) {
        unordered_map<char,int> counters;
        unordered_map<char, int> lookup; 
        unordered_set<char> missing (t.begin(), t.end());
        pair<int,int> result = make_pair(-1,-1);
        int i = 0, j = 0, slen = static_cast<int>(s.size());

        for (const auto& ch: t)
            ++lookup[ch];

        for ( ; j < slen; ++j) {
            const char ch1 = s[j];
            if (lookup.find(ch1) == lookup.end())
                continue;
            if (++counters[ch1] == lookup[ch1])
                missing.erase(ch1);
            for  ( ; missing.empty(); ++i) {
                const char ch2 = s[i];
                if (lookup.find(ch2) == lookup.end())
                    continue;
                if (--counters[ch2] < lookup[ch2]) {
                    missing.emplace(ch2);
                    if (result.first < 0 || result.second-result.first > j-i)
                        result = make_pair(i, j);
                }
            }
        }

        if (result.first < 0)
            return string();
        else
            return s.substr(result.first, result.second-result.first+1);
    }
};

int main()
{
    Solution sol;
    string S, T;

    // Expected: "BANC"
    S = "ADOBECODEBANC";
    T = "ABC";
    cout << "Result: " << sol.minWindow(S,T) << endl;

    return 0;
}

