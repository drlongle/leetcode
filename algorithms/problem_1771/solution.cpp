/*
1771. Maximize Palindrome Length From Subsequences
Hard

You are given two strings, word1 and word2. You want to construct a string in the following manner:

Choose some non-empty subsequence subsequence1 from word1.
Choose some non-empty subsequence subsequence2 from word2.
Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.

A subsequence of a string s is a string that can be made by deleting some (possibly none)
characters from s without changing the order of the remaining characters.

A palindrome is a string that reads the same forward as well as backward.

Example 1:
Input: word1 = "cacb", word2 = "cbba"
Output: 5
Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.

Example 2:
Input: word1 = "ab", word2 = "ab"
Output: 3
Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.

Example 3:
Input: word1 = "aa", word2 = "bb"
Output: 0
Explanation: You cannot construct a palindrome from the described method, so return 0.

Constraints:
1 <= word1.length, word2.length <= 1000
word1 and word2 consist of lowercase English letters.
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
    int longestPalindrome(string word1, string word2) {
        string word = word1 + word2;
        int n = word.size(), n1 = word1.size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                dp[i][j] = dp[i][j-1] > dp[i+1][j] ? dp[i][j-1] : dp[i+1][j];
                if (word[i] == word[j]) {
                    if (l == 2)
                        dp[i][j] = 2;
                    else if (dp[i+1][j-1] + 2 >= dp[i][j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    if (i < n1 && n1 <= j)
                        res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string word1, word2;

    // Output: 5
    word1 = "cacb", word2 = "cbba";
    cout << sol.longestPalindrome(word1, word2) << endl;

    // Output: 3
    word1 = "ab", word2 = "ab";
    cout << sol.longestPalindrome(word1, word2) << endl;

    // Output: 0
    word1 = "aa", word2 = "bb";
    cout << sol.longestPalindrome(word1, word2) << endl;

    // Output: 8
    word1 = "abcd", word2 = "dcba";
    cout << sol.longestPalindrome(word1, word2) << endl;

    word1 = "aabbaabbaaabbabbbbaaaaabaabaababbababbaaababbaabbabbabbaabaaabbabbabbbbbbaaaaababbaabbaaaaaabaabbbaabbaaabaaaabaaaabbabbabbabababaabbabbaabbbabbbaabbbabbbababbaaaaabbbababbabbbbbaabbaabbaaaaaaaaaabbaabaaaaaabababbbabbbbaaababbbbaaabbbabbbbaaaaabbbbbbbbabbaabaaaabbbbabaabbabaaaabbabaaababaaaabaaabababbaababbaaaaababaaababaabaaabbbaabaabbaababbbbbbbaaaabaaababbaabbbaababbbaabbaaaaaaaaabbabbbabaaaaaaabbbbaababbbabaabbbaaabbbbbaaababbaabababbababbaaaaaababbbbbbbbaababbbaaababaaaababbbabbababbbaababaaaababbbaabaabbaaaaaaaababbbbabbbabbaaaabaabbabbabaaabbabbbabaaaababaaabaaaaaaaababbbaaaaaabaaaaabbbaaaababaaababbaabbbabbbbbaaaabbbbbaabbabbbbaaaababbbabbaababbabaaababbaaaabbbabaaaaabbbaaabaaababbabbaaabaaaababbabaabaabbbabababbaaaaaaababaaabaaaabaaababbabaabbbbbaaabbaababaabbbabbaaabbaaababaaabbbaababaabaabaabbaabbaaabaabbabbbbbabaaaabaababaababababbaabbbbbbbbabbaaabbaabbaaababbbaabbbbbaaababababaababaabbabbbbbbaaaabaaaabaaabbaababaabaababaabbbbaaaababaaaaaabbabbbbbbaabbbaaaabaabbaabbaaaabaaa";
    word2 = "bbababbbbbaaaaaaaabbaabaaaaabababbbbabaababbabbabbbabbbbabbbbbabaababababbaababbbabaaababbbbbbabbbaabbabaaabaaabaaababaabaabaaaaaabaabaabaaabbaababbaababbaaabaaaabbbbababbbaabbaaaabaaabbaabbaaababbaabbbbabbbaabbaaabbbbbbaabaaaaaaabaabaababaabbbabaabbaabbababaaabaabbbbaaaaababbbaaabaabbbbabbaaabbbbbbbaabbbbbababaababbabbbaaabbbaabababbbbaabaaaaaabbaaaabbaabbbbababaaabbbbabaaabbbbaababaaabaaaabaabbaaaabbbaabaabbbbaaaaaabaabbaabaaabaaaababbbaaaaabbaabbbaabaabbbbaaaabbaabbbbbbabaabbbbabaabababababbaaaababbabbababaaaaabbaaaabbbaaaaabbbbbbbaababababbbabbbbababaabbbaababababbbbabaabbabbbaabbaabbaabbbbbbabaaaabbaabbbaaabaaaabbabaababababababaaabbababaababbbbabbbabbaabbbbbbaaaaaaabbbbaaabaabbbbabababaabbaaabbabbbbbbbbaaababaabbaababbaaabbbbbbbbabbbbabbaabbaaabababaabaabaabababaabbbabbbaabbbbabbababbbbabbbabbbaaabaaaaaabaabbbaababaaabbababaaabbaaaaabababaaaaaaababaaaaaaabaaabbaabbbbbbbabbbbaabaabbaababbaaabbbbbbaabbbbbbaababaabbbbaaaabbaaaaaababbbabaaabbaaaaabaaaaabbabbbbbbbabbabbbbbababaaaabaab";
    cout << sol.longestPalindrome(word1, word2) << endl;

    return 0;
}
