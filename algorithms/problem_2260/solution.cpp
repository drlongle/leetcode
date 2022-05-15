/*
2260. Minimum Consecutive Cards to Pick Up
Medium

You are given an integer array cards where cards[i] represents the value of the
ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a
pair of matching cards among the picked cards. If it is impossible to have
matching cards, return -1.

Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of
cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain
a pair of matching cards.

Constraints:
1 <= cards.length <= 10^5
0 <= cards[i] <= 10^6
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
    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, int> lookup;
        int res = INT_MAX;
        for (int i = 0, n = cards.size(); i < n; ++i) {
            int c = cards[i];
            auto it = lookup.find(c);
            if (it != lookup.end()) {
                res = min(res, i - it->second + 1);
                it->second = i;
            } else
                lookup[c] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> cards;

    cards = {3, 4, 2, 3, 4, 7};
    cout << sol.minimumCardPickup(cards) << endl;

    return 0;
}
