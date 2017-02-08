/*
425. Word Squares

    Difficulty: Hard

Given a set of words (without duplicates), find all word squares you can build
from them. Note:

    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.

Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter
(just the order of words in each word square matters).

Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter
(just the order of words in each word square matters).

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

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if (words.empty())
            return res;
        int wsize = words.begin()->size();
        if (wsize == 1)
        {
            for (auto& w: words)
                res.emplace_back(vector<string>(1, w));
            return res;
        }

        unordered_map<char, vector<string*>> lookup;
        for (auto& word: words)
            lookup[word[0]].emplace_back(&word);

        for (auto& word: words)
        {
            vector<string> vs;
            for (auto& ch: word)
            {
                unordered_map<char, vector<string*>>::iterator it;
                if ((it = lookup.find(ch)) == lookup.end())
                    continue;
                for (auto& w: it->second)
                    vs.emplace_back(w->substr(1));
                vector<vector<string>> subres = wordSquares(vs);
                if (subres.empty())
                    continue;
                for (auto& sub: subres)
                {
                    for (auto& s: sub)
                        s.insert(0, 1, ch);
                    sub.insert(sub.begin(), word);
                    res.emplace_back(sub);
                }
            }
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<string> words;
    vector<vector<string>> result;

    words = {"area","lead","wall","lady","ball"};
    result = sol.wordSquares(words);
    for (auto& res: result)
    {
        copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }

    return 0;
}

