/*
1657. Determine if Two Strings Are Close
Medium

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character,
and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

Example 4:
Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.

Constraints:
1 <= word1.length, word2.length <= 10^5
word1 and word2 contain only lowercase English letters.
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
    pair<vector<char>, vector<int>> get_keys(string& s) {
        unordered_map<char, int> cnt;
        for (char c: s)
            ++cnt[c];
        pair<vector<char>, vector<int>> res;
        for (auto& p: cnt) {
            res.first.emplace_back(p.first);
            res.second.emplace_back(p.second);
        }
        sort(begin(res.first), end(res.first));
        sort(begin(res.second), end(res.second));
        return res;
    }

    bool closeStrings(string word1, string word2) {
        return get_keys(word1) == get_keys(word2);
    }
};

int main() {
    Solution sol;
    string word1, word2;

    // Output: true
    word1 = "abc", word2 = "bca";
    cout << boolalpha << sol.closeStrings(word1, word2) << endl;

    // Output: false
    word1 = "a", word2 = "aa";
    cout << boolalpha << sol.closeStrings(word1, word2) << endl;

    // Output: true
    word1 = "cabbba", word2 = "abbccc";
    cout << boolalpha << sol.closeStrings(word1, word2) << endl;

    // Output: false
    word1 = "cabbba", word2 = "aabbss";
    cout << boolalpha << sol.closeStrings(word1, word2) << endl;

    // Output: false
    word1 = "uau", word2 = "ssx";
    cout << boolalpha << sol.closeStrings(word1, word2) << endl;

    return 0;
}
