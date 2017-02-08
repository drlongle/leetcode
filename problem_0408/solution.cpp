/*
408. Valid Word Abbreviation

Given a string "word" and a string "abbr", check whether "abbr" is an
abbreviation of "word". For example, valid abbreviations of "word" is
{ "1ord", "2rd", "3d", "4", "w1rd", "w2d", "w3", "wr1d", "wro1", "wr2" }
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
    s = "internationalization", abbr = "i12iz4n";
    s = "apple", abbr = "a2e";
    s = "word", abbr ="1o1d";
    s = "a", abbr = "01";
    cout << boolalpha << sol.validWordAbbreviation(s, abbr) << endl;

    return 0;
}

