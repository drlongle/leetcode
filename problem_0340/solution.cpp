/*
340. Longest Substring with At Most K Distinct Characters
Medium

Given a string s and an integer k, return the length of the longest substring of s
that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

Constraints:
1 <= s.length <= 5 * 104
0 <= k <= 50
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int head = 0, tail = 0, sz = s.size(), res = 0;
        unordered_map<char, int> cnt;
        for (; head < sz; ++head) {
            ++cnt[s[head]];
            if (cnt.size() <= k) {
                res = max(res, head - tail + 1);
            }
            while (cnt.size() > k) {
                char ch = s[tail++];
                if (--cnt[ch] == 0)
                    cnt.erase(ch);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Output: 3
    s = "eceba";
    k = 2;
    cout << s << " -> " << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;

    // Output: 2
    s = "aa", k = 1;
    cout << s << " -> " << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;

    return 0;
}
