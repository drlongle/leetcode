/*
44. Wildcard Matching
Total Accepted: 51048 Total Submissions: 300920 Difficulty: Hard

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "*") -> true
isMatch("aa", "a*") -> true
isMatch("ab", "?*") -> true
isMatch("aab", "c*a*b") -> false

https://leetcode.com/problems/wildcard-matching/
https://www.geeksforgeeks.org/wildcard-pattern-matching/
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        string pattern;
        size_t psize = p.size();
        if (psize > 0)
        {
            pattern.push_back(p[0]);
            for (size_t i = 1; i < psize; ++i)
            if (p[i] != '*' || pattern.back() != '*')
                pattern.push_back(p[i]);
        }

        return isMatch(s, 0, pattern, 0);
    }

    bool isMatch(string s, size_t s_index, string p, size_t p_index)
    {
        size_t ssize = s.size();
        size_t psize = p.size();
        if (ssize == s_index && psize == p_index)
            return true;
        if (psize == p_index)
            return false;
        if (ssize == s_index && p[p_index] != '*')
            return false;

        pair<size_t,size_t> pp(s_index,p_index);
        if (hash.find(pp) != hash.end())
            return false;
        hash.emplace(pp);

        if (p[p_index] == '*')
        {
            if (p_index == psize-1)
                return true;

            for (size_t i = s_index; i < ssize; ++i)
            {
                if (p_index+1 < psize && (p[p_index+1] != '?' &&
                    p[p_index+1] != s[i]))
                    continue;
                if (isMatch(s, i, p, p_index+1))
                    return true;
            }
        }

        if (s[s_index] == p[p_index] || p[p_index] == '?')
        {
            while (s_index < ssize && p_index < psize)
            {
                if (s[s_index] == p[p_index] || p[p_index] == '?')
                    s_index++, p_index++;
                else
                    break;
            }
            return isMatch(s,s_index, p,p_index);
        }
        return false;
    }

    set<pair<size_t,size_t>> hash;
};

int main()
{
    Solution sol;
    string st, pattern;
    st = "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab";
    pattern = "*aabb***aa**a******aa*";
    cout << "Result: " << boolalpha << sol.isMatch(st, pattern) << endl;

    return 0;
}
