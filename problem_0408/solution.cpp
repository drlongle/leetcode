/*
408. Valid Word Abbreviation

Given a non-empty string s and an abbreviation abbr, return whether the string matches
with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1",
 "1o2", "2r1", "3d", "w3", "4"]

Notice that only the above abbreviations are valid abbreviations of the string "word".
Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":
Return false.
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
    bool validWordAbbreviation(string word, string abbr) {
        if (word.empty() || abbr.empty())
            return word.empty() && abbr.empty();
        int wlen = word.size();
        int abbrlen = abbr.size();
        int windex = 0, abindex = 0;
        while (abindex < abbrlen && windex < wlen)
        {
            if (isdigit(abbr[abindex]))
            {
                if (abbr[abindex] == '0') return false;
                int abnum = 0;
                while (isdigit(abbr[abindex]))
                {
                    abnum = abnum*10 + abbr[abindex]-'0';
                    ++abindex;
                }
                windex += abnum;
                continue;
            }

            if (word[windex] != abbr[abindex])
                return false;
            else
                ++windex, ++abindex;
        }

        return (abindex == abbrlen) && (windex == wlen);
    }
};

int main()
{
    Solution sol;
    string s, abbr;

    // true
    s = "internationalization", abbr = "i12iz4n";
    cout << boolalpha << sol.validWordAbbreviation(s, abbr) << endl;

    // false
    s = "apple", abbr = "a2e";
    cout << boolalpha << sol.validWordAbbreviation(s, abbr) << endl;

    // true
    s = "word", abbr ="1o1d";
    cout << boolalpha << sol.validWordAbbreviation(s, abbr) << endl;

    // false
    s = "a", abbr = "01";
    cout << boolalpha << sol.validWordAbbreviation(s, abbr) << endl;

    return 0;
}

