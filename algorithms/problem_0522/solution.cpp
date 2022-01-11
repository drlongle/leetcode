/*
522. Longest Uncommon Subsequence II
Medium

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is
defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of
the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.
If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:
All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Main idea: Find the longest string that is not dplicated and is not a sequence
of any other strings. That string is the longest uncommon subsequence.
*/

class Solution {
public:
    bool contains(string& s1, string& s2) {
        size_t pos = -1;
        for (char ch: s2) {
            pos = s1.find(ch, pos+1);
            if (pos == string::npos)
                return false;
        }

        return true;
    }
    int findLUSlength(vector<string>& strs) {
        auto lambda = [] (auto& s1, auto& s2) {
            return s1.size() > s2.size() || (s1.size() == s2.size() && s1 > s2);
        };
        sort(begin(strs), end(strs), lambda);
        int i = 0, sz = strs.size();
        for (i = 0; i < sz; ++i) {
            if (i < sz - 1 && strs[i] == strs[i+1]) {
                ++i;
                continue;
            } else {
                bool subseq = false;
                for (int j = 0; j < i; ++j) {
                    if (contains(strs[j], strs[i])) {
                        subseq = true;
                        break;
                    }
                }
                if (!subseq) {
                    break;
                }
            }
        }
        if (i == sz)
            return -1;
        return strs[i].size();
    }
};

int main() {
    Solution sol;
    vector<string> strs;

    // Output: 3
    strs = {"aba", "cdc", "eae"};
    cout << sol.findLUSlength(strs) << endl;

    // Output: -1
    strs = {"aaa","aaa","aa"};
    cout << sol.findLUSlength(strs) << endl;

    // Output: 2
    strs = {"aabbcc", "aabbcc","cb","abc"};
    cout << sol.findLUSlength(strs) << endl;

    // Output: -1
    strs = {"a","b","c","d","e","f","a","b","c","d","e","f"};
    cout << sol.findLUSlength(strs) << endl;

    // Output: 3
    strs = {"abcabc","abcabc","abcabc","abc","abc","cca"};
    cout << sol.findLUSlength(strs) << endl;

    return 0;
}
