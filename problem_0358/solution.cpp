/*
358. Rearrange String k Distance Apart
Hard

Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other.
If it is not possible to rearrange the string, return an empty string "".

Example 1:
Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least a distance of 3 from each other.

Example 2:
Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.

Example 3:
Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least a distance of 2 from each other.

Constraints:
1 <= s.length <= 3 * 10^5
s consists of only lowercase English letters.
0 <= k <= s.length
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c: s)
            ++cnt[c - 'a'];
        multimap<int, char, greater<int>> m;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i])
                m.emplace(cnt[i], 'a' + i);
        }
        vector<int> pos(26, -1);
        int i = 0;
        while (m.size()) {
            bool inserted = false;
            for (auto it = begin(m); it != end(m) && !inserted; ++it) {
                char c = it->second;
                int index = c - 'a';
                if (pos[index] < 0 || i - pos[index] >= k) {
                    pos[index] = i;
                    s[i++] = c;
                    int cnt = it->first - 1;
                    m.erase(it);
                    if (cnt > 0)
                        m.emplace(cnt, c);
                    inserted = true;
                    break;
                }
            }
            if (!inserted)
                return "";
        }

        return s;
    }
};

int main() {
    Solution sol;

    return 0;
}
