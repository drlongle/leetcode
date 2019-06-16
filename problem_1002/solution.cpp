/*
1002. Find Common Characters
Difficulty: Easy

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: ["cool","lock","cook"]
Output: ["c","o"]
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    void update_counts(const string& st) {
        map<char, int> local_counts;
        for (char ch: st)
            ++local_counts[ch];
        for (auto& c: counts) {
            c.second = min(c.second, local_counts[c.first]);
        }
    }

    vector<string> commonChars(vector<string>& str_list) {
        vector<string> res;
        int lsize = str_list.size();
        if (!lsize)
            return res;
        for (char ch: str_list[0])
            ++counts[ch];

        for (int i = 1; i < lsize; ++i)
            update_counts(str_list[i]);

        for (auto& c: counts) {
            for (int i = 0; i < c.second; ++i)
                res.emplace_back(string(1, c.first));
        }

        return res;
    }

    map<char, int> counts;
};

int main() {
    Solution sol;
    vector<string> str_list, res;

    // Expected: ["e","l","l"]
    str_list = {"bella","label","roller"};

    // Expected: ["c","o"]
    // str_list = {"cool","lock","cook"};

    res = sol.commonChars(str_list);
    copy(begin(res), end(res), ostream_iterator<string>(cout, " "));

    return 0;
}

