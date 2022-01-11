/*
1897. Redistribute Characters to Make All Strings Equal
Easy

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string,
and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

Example 1:
Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.

Example 2:
Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        int sz = words.size();
        for (auto& w: words) {
            for (auto c: w)
                ++cnt[c - 'a'];
        }
        for (int c: cnt) {
            if (c % sz != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> words;

    // True
    words = {"aaaaaaaaaaaaaaaaa","aaa","bbbbbbbbbbbbbbbb","bbb","b","ccccccccccccccccccccccccccccc","ccccccccccc",
             "dddddddddddddd","dddddddddddddddddddddddd","dddddddddddddddddddddddddddddddddddddddddddddd",
             "ddddddddddddddddddddddddddddddddddddddddddddddddd","dddddddddddddd","dddd","ddddddddd",
             "eeeeeeeeeeeeeee","eeeeeeeeeeeeee","ee","eeeeee","e","ee"};
    cout << sol.makeEqual(words) << endl;

    return 0;
}
