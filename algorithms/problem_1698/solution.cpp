/*
1698. Number of Distinct Substrings in a String
Medium

Given a string s, return the number of distinct substrings of s.

A substring of a string is obtained by deleting any number of characters (possibly zero) from
the front of the string and any number (possibly zero) from the back of the string.

Example 1:
Input: s = "aabbaba"
Output: 21
Explanation: The set of distinct strings is ["a","b","aa","bb","ab","ba","aab","abb","bab",
"bba","aba","aabb","abba","bbab","baba","aabba","abbab","bbaba","aabbab","abbaba","aabbaba"]

Example 2:
Input: s = "abcdefg"
Output: 28

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.

Follow up: Can you solve this problem in O(n) time complexity?
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
    unordered_set<string> table;
    int countDistinct(string s) {
        int n = s.size();
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                table.emplace(s.substr(i, len));
            }
        }

        return table.size();
    }
};

int main() {
    Solution sol;

    return 0;
}
