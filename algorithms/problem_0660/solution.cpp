/*
660. Remove 9
Hard

Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

Now, you will have a new integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...].

Given an integer n, return the nth (1-indexed) integer in the new sequence.

Example 1:
Input: n = 9
Output: 10

Example 2:
Input: n = 10
Output: 11

Constraints:
1 <= n <= 8 * 10^8
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

class Solution {
public:
    using ll = long long;
    vector<ll> drops{0};
    vector<ll> pow{1};

    ll count(ll n) {
        ll res = 0;
        for (int i = 9; i > 0; --i) {
            int p = pow[i];
            int k = n / p;
            res += drops[i] * k;
            n %= p;
            if (k == 9) {
                res += n + 1;
                return res;
            }
        }

        return  res;
    }

    ll count(int from, int to) {
        return count(to) - count(from);
    }

    int newInteger(ll n) {
        for (int i = 1; i <= 9; ++i) {
            ll p = pow.back();
            ll n = drops.back() * 9 + p;
            pow.push_back(p * 10);
            drops.push_back(n);
        }

        ll start = 1, drops = 1;
        while (drops > 0) {
            drops = count(start, n);
            start = n;
            n += drops;
        }

        while (true) {
            string s = to_string(n);
            if (s.find('9') == string::npos)
                break;
            else
                ++n;
        }

        return n;
    }
};

int main() {
    Solution sol;

    return 0;
}
