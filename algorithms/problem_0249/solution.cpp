/*
249. Group Shifted Strings
Medium

Given a string, we can "shift" each of its letter to its successive letter, for example:
"abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"

Given a list of non-empty strings which contains only lowercase alphabets, group all strings
that belong to the same shifting sequence.

Example:
Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    string key(string& s) {
        string res(s);
        int diff = s[0] - 'a';
        if (diff > 0) {
            for (char& c: res) {
                c -= diff;
                c += (c < 'a') ? 26 : 0;
            }

        }

        return res;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> table;
        for (auto& s: strings)
            table[key(s)].emplace_back(s);
        vector<vector<string>> res;
        for (auto& v: table)
            res.push_back(move(v.second));
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
