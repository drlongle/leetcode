/*
392. Is Subsequence
Difficulty: Medium

Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t.
t is potentially a very long (length ~= 500,000) string, and s is a short
string (<=100).

A subsequence of a string is a new string which is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (ie, "ace" is a subsequence of
"abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
want to check one by one to see if T has its subsequence. In this scenario, how
would you change your code?
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    bool isSubsequence2(string s, string t) {
        map<char, set<int>> pos;
        for (int i = 0; i < t.size(); ++i)
            pos[t[i]].emplace(i);
        
        for (int si = 0, ti = -1;si < s.size(); ++si) {
            auto it1 = pos.find(s[si]);
            if (it1 == pos.cend())
                return false;
            auto it2 = it1->second.upper_bound(ti);
            if (it2 == it1->second.cend())
                return false;
            ti = *it2;
        }
        
        return true;
    }

    bool isSubsequence(string s, string t) {
        map<char, queue<int>> pos;
        for (int i = 0; i < t.size(); ++i)
            pos[t[i]].emplace(i);
        
        for (int si = 0, ti = -1; si < s.size(); ++si) {
            auto it = pos.find(s[si]);
            if (it == pos.cend())
                return false;
            bool found = false;
            while (!it->second.empty() && !found) {
                if (ti  <= it->second.front()) {
                    ti = it->second.front();
                    found = true;
                }
            }
            if (!found)
                return false;
        }
        
        return true;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    string s, t;

    // Expected: true
    s = "abc", t = "ahbgdc";
    cout << "Result: " << boolalpha << sol.isSubsequence(s, t) << endl;

    // Expected: false
    s = "axc", t = "ahbgdc";
    cout << "Result: " << boolalpha << sol.isSubsequence(s, t) << endl;
    
    return 0;
}
