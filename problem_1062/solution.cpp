/*
1062. Longest Repeating Substring
Medium

Given a string S, find out the length of the longest repeating substring(s).
Return 0 if no repeating substring exists.

Example 1:
Input: S = "abcd"
Output: 0
Explanation: There is no repeating substring.

Example 2:
Input: S = "abbaba"
Output: 2
Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice.

Example 3:
Input: S = "aabcaabdaab"
Output: 3
Explanation: The longest repeating substring is "aab", which occurs 3 times.

Example 4:
Input: S = "aaaaa"
Output: 4
Explanation: The longest repeating substring is "aaaa", which occurs twice.

Constraints:
The string S consists of only lowercase English letters from 'a' - 'z'.
1 <= S.length <= 1500
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

    static constexpr int MOD = 10000007;

    inline bool compare (string & s, int i, int j, int k) {
        while (k-- > 0)
            if (s[i--] != s [j--])
                return false;
        return true;
    }

    int longestRepeatingSubstring(string s) {
        vector <int> prod {1};

        for (int k = 1, p  = 1; k < (int) s.size (); ++k) {
            p = p * 26 % MOD;
            prod.push_back(p);
        }

        for(int k = s.size()-1; k >= 1; --k) {
            unordered_map<int, vector<int>> tab;

            for (int sum = 0, i = 0; i < (int) s.size(); ++i) {
                sum = (sum * 26 + s[i] - 'a' - (i >= k ? (s[i-k] - 'a') * prod[k] : 0)) % MOD;
                if (sum < 0) {
                    sum  += MOD;

                }
                if (i >= k-1) {
                    auto& v = tab[sum];
                    for (int j: v) {
                        if (compare(s, i, j, k))
                            return k;
                    }
                    v.push_back (i);
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;

    return 0;
}
