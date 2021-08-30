/*
1088. Confusing Number II
Hard

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

We can rotate digits of a number by 180 degrees to form new digits.

When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6 respectively.
When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.
Note that after rotating a number, we can ignore leading zeros.

For example, after rotating 8000, we have 0008 which is considered as just 8.
Given an integer n, return the number of confusing numbers in the inclusive range [1, n].

Example 1:
Input: n = 20
Output: 6
Explanation: The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.

Example 2:
Input: n = 100
Output: 19
Explanation: The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100].

Constraints:
1 <= n <= 10^9
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
    string reverse(string& s) {
        string r;
        for (int i = s.size() - 1; i >= 0; --i) {
            char ch = s[i];
            if (ch == '6')
                ch = '9';
            else if (ch == '9')
                ch = '6';
            r.push_back(ch);
        }
        return r;
    }

    void backtrack(string& s, string& limit) {
        if (s.size() && (s.size() < limit.size() || (s.size() == limit.size() && s <= limit))) {
            string r = reverse(s);
            res += (r != s);
        }
        if (s.size() == limit.size())
            return;
        for (auto ch: chs) {
            if (ch == '0' && s.empty())
                continue;
            s.push_back(ch);
            backtrack(s, limit);
            s.pop_back();
        }
    }

    int res = 0;
    vector<char> chs{'0', '1', '6', '8', '9'};
    int confusingNumberII(int n) {
        string s, limit = to_string(n);
        backtrack(s, limit);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
