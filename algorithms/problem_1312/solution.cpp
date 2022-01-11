/*
1312. Minimum Insertion Steps to Make a String Palindrome
Hard

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Example 4:
Input: s = "g"
Output: 0

Example 5:
Input: s = "no"
Output: 1

Constraints:
1 <= s.length <= 500
All characters of s are lower case English letters.
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
    int minInsertions(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int len = 1; len <= sz; ++len) {
            for (int i = 0; i + len - 1 < sz; ++i) {
                int j = i + len - 1;
                switch (len) {
                    case 1:
                        dp[i][j] = 0;
                        break;
                    case 2:
                        dp[i][j] = (s[i] == s[j]) ? 0 : 1;
                        break;
                    default:
                        if (s[i] == s[j])
                            dp[i][j] = dp[i+1][j-1];
                        else
                            dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][sz-1];
    }
};

int main() {
    return 0;
}
