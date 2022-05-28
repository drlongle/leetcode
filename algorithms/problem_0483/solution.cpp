/*
483. Smallest Good Base
Hard

Given an integer n represented as a string, return the smallest good base of n.
We call k >= 2 a good base of n, if all digits of n base k are 1's.

Example 1:
Input: n = "13"
Output: "3"
Explanation: 13 base 3 is 111.

Example 2:
Input: n = "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

Example 3:
Input: n = "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.

Constraints:
n is an integer in the range [3, 101^8].
n does not contain any leading zeros.
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

    ll check(ll n, int len) {
        ll lo = 1, hi = n, res = -1;
        while (lo <= hi) {
            ll mult = 0;
            ll mid = (lo + hi) / 2;
            ll limit = n / mid;
            bool valid = true;
            for (int i = 0; i < len; ++i) {
                if (mult > limit) {
                    valid = false;
                    break;
                }
                mult = mult * mid + 1;
            }
            if (!valid || mult > n)
                hi = mid - 1;
            else if (mult == n)
                return mid;
            else
                lo = mid + 1;
        }

        return res;
    }

    string smallestGoodBase(string n) {
        ll num = std::stoll(n);
        for (int len = ceil(log2(num)); len > 0; --len) {
            auto r = check(num, len);
            if (r > 0) {
                return to_string(r);
            }
        }

        return to_string(-1);
    }
};

int main() {
    Solution sol;

    return 0;
}
