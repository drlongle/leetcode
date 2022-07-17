/*
475. Heaters
Medium

Winter is coming! During the contest, your first job is to design a standard
heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm
radius range.

Given the positions of houses and heaters on a horizontal line, return the
minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius
will the same.

Example 1:
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the
radius 1 standard, then all the houses can be warmed.

Example 2:
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use
radius 1 standard, then all the houses can be warmed.

Example 3:
Input: houses = [1,5], heaters = [2]
Output: 3

Constraints:
1 <= houses.length, heaters.length <= 3 * 10^4
1 <= houses[i], heaters[i] <= 10^9
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
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        set<int> lookup(begin(heaters), end(heaters));
        int res = 0;
        for (int house : houses) {
            auto it = lookup.lower_bound(house);
            int distance = INT_MAX;
            if (it != lookup.end())
                distance = *it - house;
            if (it != lookup.begin()) {
                distance = min(distance, house - *(--it));
            }
            res = max(res, distance);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> houses, heaters;

    // Expected: 1
    houses = {1, 2, 3}, heaters = {2};
    cout << sol.findRadius(houses, heaters) << endl;

    // Expected: 1
    houses = {1, 2, 3, 4}, heaters = {1, 4};
    cout << sol.findRadius(houses, heaters) << endl;

    // Expected: 3
    houses = {1, 5}, heaters = {2};
    cout << sol.findRadius(houses, heaters) << endl;

    return 0;
}