/*
1278. Palindrome Partitioning III
Hard

You are given a string s containing lowercase letters and an integer k. You need to :

First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
Return the minimal number of characters that you need to change to divide the string.

Example 1:
Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.

Example 2:
Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.

Example 3:
Input: s = "leetcode", k = 8
Output: 0

Constraints:

1 <= k <= s.length <= 100.
s only contains lowercase English letters
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

    void expand(string& s, int i, int j) {
        if (i == j)
            changes[i][j] = 0;
        if (i+1 == j)
            changes[i][j] = (s[i] == s[j]) ? 0 : 1;

        while (true) {
            --i;
            ++j;
            if (i < 0 || j >= sz)
                break;
            changes[i][j] = changes[i+1][j-1] + ((s[i] == s[j]) ? 0 : 1);
        }
    }

    int palindromePartition(string& s, const int K) {
        sz = s.size();
        changes.resize(sz, vector<int>(sz));

        for (int i = 0; i < sz; ++i) {
            expand(s, i, i);
            if (i < sz-1)
                expand(s, i, i+1);
        }

        vector<int> dp(changes[0]);
        for (int k = 2; k <= K; ++k) {
            vector<int> dp2(sz, numeric_limits<int>::max());
            for (int i = k-1; i < sz; ++i) {
                for (int j = i-1; j >= k-2; --j) {
                    dp2[i] = min(dp2[i], dp[j] + changes[j+1][i]);
                }
            }
            dp = dp2;
        }

        return dp[sz-1];
    }

    vector<vector<int>> changes;
    int sz;
};

int main() {
    Solution sol;
    return 0;
}
