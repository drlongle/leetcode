/*
583. Delete Operation for Two Strings
Medium

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
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
    vector<vector<int>> dp;
    int n1, n2;

    int minDistance(string& word1, string& word2, int  index1, int index2) {
        if (index1 == n1)
            return n2 - index2;
        if (index2 == n2)
            return n1 - index1;

        int& res = dp[index1][index2];
        if (res >= 0)
            return res;
        if (word1[index1] == word2[index2])
            res = minDistance(word1, word2, index1+1, index2+1);
        else {
            res = 1 + min(minDistance(word1, word2, index1, index2+1),
                          minDistance(word1, word2, index1+1, index2));
        }
        return res;
    }

    int minDistance(string word1, string word2) {
        n1 = word1.size(), n2 = word2.size();
        dp.resize(n1, vector<int>(n2, -1));
        return minDistance(word1, word2, 0, 0);
    }
};

int main() {
    string word1, word2;

    // Output: 2
    {
        Solution sol;
        word1 = "sea", word2 = "eat";
        cout << sol.minDistance(word1, word2) << endl;
    }

    // Output: 4
    {
        Solution sol;
        word1 = "leetcode", word2 = "etco";
        cout << sol.minDistance(word1, word2) << endl;
    }

    // Output: 0
    {
        Solution sol;
        word1 = "a", word2 = "a";
        cout << sol.minDistance(word1, word2) << endl;
    }

    // Output: 1
    {
        Solution sol;
        word1 = "a", word2 = "b";
        cout << sol.minDistance(word1, word2) << endl;
    }

    // Output: 5
    {
        Solution sol;
        word1 = "mart", word2 = "karma";
        cout << sol.minDistance(word1, word2) << endl;
    }

    return 0;
}
