/*
205. Isomorphic Strings
Total Accepted: 61787 Total Submissions: 203588 Difficulty: Easy

Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
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
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
             return false;
        unordered_map<char,char> table1, table2;
        int ssize = s.size();
        for (int i = 0; i < ssize; ++i)
        {
            unordered_map<char,char>::iterator it = table1.find(s[i]);
            if (it != table1.end())
            {
                if (it->second != t[i])
                    return false;
            }
            else
                table1[s[i]] = t[i];

            it = table2.find(t[i]);
            if (it != table2.end())
            {
                if (it->second != s[i])
                    return false;
            }
            else
                table2[t[i]] = s[i];
        }

        return true;    
    }
};

int main()
{
    Solution sol;
    string s, t;

    // Expected: false
    s = "ab";
    t = "aa";
    cout << "Result: " << boolalpha << sol.isIsomorphic(s,t) << endl;

    return 0;
}

