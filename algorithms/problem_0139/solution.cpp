/*
139. Word Break
Medium

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine
if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
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

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int sz = s.size();
        vector<bool> bs(sz, false);
        for (int i = 0; i < sz; ++i) {
            if (dict.count(s.substr(0, i+1))) {
                bs[i] = true;
            }

            for (int j = 0; j < i && !bs[i]; ++j) {
                bs[i] = bs[j] && dict.count(s.substr(j+1, i-j));
            }
        }
        return bs[sz-1];
    }
};

int main() {
    Solution sol;
    vector<string> wordDict;
    string s;

    // Output: true
    s = "leetcode", wordDict = {"leet", "code"};
    cout << boolalpha << sol.wordBreak(s, wordDict) << endl;

    // Output: true
    s = "applepenapple", wordDict = {"apple", "pen"};
    cout << boolalpha << sol.wordBreak(s, wordDict) << endl;

    // Output: false
    s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << boolalpha << sol.wordBreak(s, wordDict) << endl;

    return 0;
}
