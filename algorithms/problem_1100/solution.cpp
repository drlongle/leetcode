/*
1100. Find K-Length Substrings With No Repeated Characters
Medium

Given a string s, return the number of substrings of length k with no repeated characters.

Example 1:
Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation:
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:
Input: s = "home", k = 5
Output: 0
Explanation:
Notice k can be larger than the length of s. In this case is not possible to find any substring.

Note:
1 <= s.length <= 10^4
All characters of s are lowercase English letters.
1 <= k <= 10^4
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int res = 0;
        unordered_map<char, int> cnt;
        for (int i = 0, n = s.size(); i < n; ++i) {
            ++cnt[s[i]];
            res += (cnt.size() == k);
            if (i >= k-1) {
                char c = s[i-k+1];
                if (--cnt[c] == 0)
                    cnt.erase(c);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
