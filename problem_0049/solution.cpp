/*
49. Group Anagrams
Total Accepted: 76661 Total Submissions: 275152 Difficulty: Medium

Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.
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
    vector<vector<string>> groupAnagrams(vector<string>& strs);
};

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result; 
    unordered_map<string, vector<string>> lookup;
    for (const auto& s: strs)
    {
        auto t = s;
        sort(t.begin(), t.end());
        lookup[t].emplace_back(s);
    }

    for (auto& h : lookup)
    {
        sort(h.second.begin(), h.second.end());
        result.emplace_back(h.second);
    }

    return result;
}

int main()
{
    Solution sol;

    return 0;
}

