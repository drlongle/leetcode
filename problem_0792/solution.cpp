/*
792. Number of Matching Subsequences
Medium

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none)
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

Constraints:
1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = 0;
        for (string& word: words) {
            int curr = 0;
            bool matched = true;
            for (char ch: word) {
                auto& index = pos[ch - 'a'];
                auto it = lower_bound(begin(index), end(index), curr);
                if (it == end(index)) {
                    matched = false;
                    break;
                }
                curr = *it + 1;
            }
            res += matched;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string s;

    // Output: 3
    s = "abcde", words = {"a","bb","acd","ace"};
    cout << sol.numMatchingSubseq(s, words) << endl;

    // Output: 2
    s = "dsahjpjauf", words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << sol.numMatchingSubseq(s, words) << endl;

    return 0;
}
