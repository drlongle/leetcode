/*
524. Longest Word in Dictionary through Deleting
Medium

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
Output: 
"apple"

Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<set<int>> lookup;

    bool isSubsequence(string &s) {
        int currpos = 0;
        for (char ch: s) {
            auto it = lookup[ch-'a'].lower_bound(currpos);
            if (it == lookup[ch-'a'].end())
                return false;
            currpos = *it + 1;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& d) {
        lookup.clear();
        lookup.resize(26);
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            lookup[s[i] - 'a'].emplace(i);
        }
        string matched;
        for (string& cand: d) {
            if (isSubsequence(cand)) {
                if (cand.size() > matched.size() || (cand.size() == matched.size() && cand < matched))
                    matched = cand;
            }
        }

        return matched;
    }
};

int main() {
    Solution sol;
    return 0;
}
