/*
2131. Longest Palindrome by Concatenating Two Letter Words
Medium

You are given an array of strings words. Each element of words consists of two
lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and
concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is
impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of
length 6. Note that "clgglc" is another longest palindrome that can be created.

Example 2:
Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt",
of length 8. Note that "lcyttycl" is another longest palindrome that can be
created.

Example 3:
Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is
"xx".

Constraints:
1 <= words.length <= 10^5
words[i].length == 2
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int longestPalindrome(vector<string> &words) {
        int res = 0;
        unordered_map<string, int> counters;
        for (auto &word : words) {
            auto it = counters.find(word);
            if (it != counters.end() && it->second > 0) {
                --it->second;
                res += 4;
            } else {
                reverse(word.begin(), word.end());
                ++counters[word];
            }

            // cout<<word<< "-"<<res<<endl;
        }

        for (const auto &[k, v] : counters) {
            if (v > 0 && k[0] == k[1]) {
                res += 2;
                break;
            }
        }

        return res;
    }
};

int main() { return 0; }
