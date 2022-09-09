/*
1996. The Number of Weak Characters in the Game
Medium

You are playing a game that contains multiple characters, and each of the
characters has two main properties: attack and defense. You are given a 2D
integer array properties where properties[i] = [attacki, defensei] represents
the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and
defense levels strictly greater than this character's attack and defense levels.
More formally, a character i is said to be weak if there exists another
character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

Example 1:
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the
other.

Example 2:
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a
strictly greater attack and defense.

Example 3:
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a
strictly greater attack and defense.

Constraints:
2 <= properties.length <= 10^5
properties[i].length == 2
1 <= attacki, defensei <= 10^5
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
    int numberOfWeakCharacters(vector<vector<int>> &props) {
        sort(begin(props), end(props), [](const auto &a, const auto &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int max_seen = 0;
        int res = 0;
        for (auto &prop : props) {
            if (prop[1] < max_seen)
                ++res;
            max_seen = max(max_seen, prop[1]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> properties;

    // Output: 0
    properties = {{5, 5}, {6, 3}, {3, 6}};
    cout << sol.numberOfWeakCharacters(properties) << endl;

    // Output: 1
    properties = {{2, 2}, {3, 3}};
    cout << sol.numberOfWeakCharacters(properties) << endl;

    // Output: 1
    properties = {{1, 5}, {10, 4}, {4, 3}};
    cout << sol.numberOfWeakCharacters(properties) << endl;

    // Output: 4
    properties = {{10, 1}, {5, 1}, {7, 10}, {4, 1},
                  {5, 9},  {6, 9}, {7, 2},  {1, 10}};
    cout << sol.numberOfWeakCharacters(properties) << endl;
}
