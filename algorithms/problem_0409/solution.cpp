/*
409. Longest Palindrome

    Total Accepted: 725
    Total Submissions: 1495
    Difficulty: Easy

Given a string which consists of lowercase or uppercase letters, find the
length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note: Assume the length of given string will not exceed 1,010.

Example:
Input: "abccccdd"
Output: 7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int longestPalindrome(string s)
    {
        map<char, int> counters;
        for (const auto& c: s)
            ++counters[c];
        int len = 0;
        bool found_odd = false;
        for (const auto& p: counters)
        {
            if (p.second & 1)
            {
                if (!found_odd)
                {
                    len += p.second;
                    found_odd = true;
                }
                else
                    len += p.second-1;
            }
            else
                len += p.second;
        }
        return len;
    }
};

int main()
{
    Solution sol;
    string s;

    s = "abccccdd";
    cout << "Result: " << sol.longestPalindrome(s) << endl;

    return 0;
}

