/*
1662. Check If Two String Arrays are Equivalent
Easy

Given two string arrays word1 and word2, return true if the two arrays represent the same string,
and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true

Constraints:
1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
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
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        size_t i1 = 0, i2 = 0, j1 = 0, j2 = 0, n1 = word1.size(), n2 = word2.size();
        while (true) {
            if (j1 == word1[i1].size()) {
                j1 = 0;
                ++i1;
            }
            if (j2 == word2[i2].size()) {
                j2 = 0;
                ++i2;
            }
            if (i1 == n1 || i2 == n2)
                break;
            if (word1[i1][j1++] != word2[i2][j2++])
                return false;
        }

        return i1 == n1 && i2 == n2 && j1 == 0 && j2 == 0;
    }
};

int main() {
    Solution sol;
    vector<string> word1, word2;

    // true
    word1 = {"ab", "c"}, word2 = {"a", "bc"};
    cout << boolalpha << sol.arrayStringsAreEqual(word1, word2) << endl;

    // false
    word1 = {"a", "cb"}, word2 = {"ab", "c"};
    cout << boolalpha << sol.arrayStringsAreEqual(word1, word2) << endl;

    // true
    word1  = {"abc", "d", "defg"}, word2 = {"abcddefg"};
    cout << boolalpha << sol.arrayStringsAreEqual(word1, word2) << endl;

    return 0;
}
