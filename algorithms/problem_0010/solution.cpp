/*
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") -> false
isMatch("abcd", "d*") -> false
isMatch("aaa", "ab*a") -> false
isMatch("a", "ab*") -> true
isMatch("a", ".*..a*") -> false
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p)
    {
        int slen = static_cast<int>(s.size());
        int plen = static_cast<int>(p.size());
        if (plen == 0 && slen == 0)
            return true;
        if (plen == 0)
            return false;

        if (slen > 0 && plen > 0) {
            const char& sback = s.back();
            const char& pback = p.back();
            if (pback != '.' && pback != '*' && pback != sback)
                return false;
        }
 
        if (plen > 1 && p[1] == '*') {
            if (isMatch(s, p.substr(2)))
                return true;
            if (s[0] == p[0] || p[0] == '.') {
                for (int i = 0; i < slen; ++i) {
                    if (s[i] != s[0] && p[0] != '.')
                        break;
                    if (isMatch(s.substr(i+1), p.substr(2)))
                        return true;
                }
            }
        }

        if (slen > 0 && (s[0] == p[0] || p[0] == '.') &&
            isMatch(s.substr(1), p.substr(1)))
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    string s; 
    string p;
    cin >> s >> p;
    cout << "s: " << s << ", p: " << p << ": "
         << (solution.isMatch(s.c_str(), p.c_str()) ? "match" : "no match");
}

