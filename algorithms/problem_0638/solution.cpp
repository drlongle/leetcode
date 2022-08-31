/*
638. Shopping Offers
Medium

In LeetCode Store, there are n items to sell. Each item has a price. However,
there are some special offers, and a special offer consists of one or more
different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith
item, and an integer array needs where needs[i] is the number of pieces of the
ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where
special[i][j] is the number of pieces of the jth item in the ith offer and
special[i][n] (i.e., the last integer in the array) is the price of the ith
offer.

Return the lowest price you have to pay for exactly certain items as given,
where you could make optimal use of the special offers. You are not allowed to
buy more items than you want, even if that would lower the overall price. You
could use any of the special offers as many times as you want.

Example 1:
Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5
respectively. In special offer 1, you can pay $5 for 3A and 0B In special offer
2, you can pay $10 for 1A and 2B. You need to buy 3A and 2B, so you may pay $10
for 1A and 2B (special offer #2), and $4 for 2A.

Example 2:
Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
Output: 11
Explanation: The price of A is $2, and $3 for B, $4 for C.
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer
#1), and $3 for 1B, $4 for 1C. You cannot add more items, though only $9 for 2A
,2B and 1C.

Constraints:
n == price.length == needs.length
1 <= n <= 6
0 <= price[i], needs[i] <= 10
1 <= special.length <= 100
special[i].length == n + 1
0 <= special[i][j] <= 50
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
    map<int, int> seen;
    int res = numeric_limits<int>::max(), n;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs) {
        n = needs.size();
        needs.push_back(0);
        shop(price, special, needs);

        return res;
    }

    void shop(vector<int> &price, vector<vector<int>> &special,
              vector<int> &needs) {
        if (needs[n] >= res)
            return;
        bool reach = true;

        int key = 0;
        int mult = 1;
        for (int i = 0; i < n; ++i) {
            reach &= (needs[i] == 0);
            key += needs[i] * mult;
            mult *= 11;
        }
        if (reach) {
            res = min(res, needs[n]);
            return;
        }
        auto it = seen.find(key);
        if (it != seen.end()) {
            if (it->second <= needs[n])
                return;
            it->second = needs[n];
        } else
            seen[key] = needs[n];
        vector<int> new_needs;
        for (auto &s : special) {
            new_needs = needs;
            bool valid = true;
            for (int i = 0; valid && i < n; ++i) {
                new_needs[i] -= s[i];
                valid = (new_needs[i] >= 0);
            }
            if (valid) {
                new_needs[n] += s[n];
                shop(price, special, new_needs);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (needs[i] > 0) {
                --needs[i];
                needs.back() += price[i];
                shop(price, special, needs);
                ++needs[i];
                needs.back() -= price[i];
            }
        }
    }
};

int main() {
    vector<vector<int>> special;
    vector<int> price, needs;

    // Output: 14
    {
        Solution sol;
        price = {2, 5}, special = {{3, 0, 5}, {1, 2, 10}}, needs = {3, 2};
        cout << sol.shoppingOffers(price, special, needs) << endl;
    }

    // Output: 11
    {
        Solution sol;
        price = {2, 3, 4}, special = {{1, 1, 0, 4}, {2, 2, 1, 9}},
        needs = {1, 2, 1};
        cout << sol.shoppingOffers(price, special, needs) << endl;
    }

    // Output: 2
    {
        Solution sol;
        price = {9, 9};
        special = {{1, 1, 1}};
        needs = {2, 2};
        cout << sol.shoppingOffers(price, special, needs) << endl;
    }
}
