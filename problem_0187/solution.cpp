/*
187. Repeated DNA Sequences
Total Accepted: 44410 Total Submissions: 172493 Difficulty: Medium

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that
occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include <algorithm>
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
    vector<string> findRepeatedDnaSequences(string s);
};

vector<string> Solution::findRepeatedDnaSequences(string s)
{
    vector<string> result;
    unordered_map<string, int> counters;
    for (int i = 0; i <= static_cast<int>(s.size())-10; ++i)
    {
        string subs = s.substr(i, 10);
        ++counters[subs];
    }
    
    for (const auto& c: counters)
    {
        if (c.second > 1)
            result.emplace_back(c.first);
    }
    return result;
}

int main()
{
    Solution sol;
    vector<string> result;
    string s;
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    result = sol.findRepeatedDnaSequences(s);
    cout << "Result:" << endl;
    for (const auto& r: result)
        cout << r << endl;
    return 0;
}

