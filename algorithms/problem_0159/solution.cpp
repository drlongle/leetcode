/*
159. Longest Substring with At Most Two Distinct Characters
Medium

Given a string s , find the length of the longest substring t that contains at most 2 distinct characters.

Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int head = 0, tail = 0, sz = s.size(), res = 0;
        unordered_map<char, int> cnt;
        for (; head < sz; ++head) {
            ++cnt[s[head]];
            if (cnt.size() <= 2) {
                res = max(res, head - tail + 1);
            }
            while (cnt.size() > 2) {
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

    // Output: 3
    s = "eceba";
    cout << s << " -> " << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;

    // Output: 5
    s = "ccaabbb";
    cout << s << " -> " << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;

    return 0;
}
