/*
904. Fruit Into Baskets
Medium

You are visiting a farm that has a single row of fruit trees arranged from left
to right. The trees are represented by an integer array fruits where fruits[i]
is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some
strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold. Starting from any
tree of your choice, you must pick exactly one fruit from every tree (including
the start tree) while moving to the right. The picked fruits must fit in one of
your baskets. Once you reach a tree with fruit that cannot fit in your baskets,
you must stop. Given the integer array fruits, return the maximum number of
fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

Constraints:
1 <= fruits.length <= 10^5
0 <= fruits[i] < fruits.length
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
    int totalFruit(vector<int> &fruits) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int sz = fruits.size(), head = 0, tail = 0; head < sz; ++head) {
            ++cnt[fruits[head]];
            while (cnt.size() > 2) {
                int id = fruits[tail];
                if (--cnt[id] == 0) {
                    cnt.erase(id);
                }
                ++tail;
            }
            int t = 0;
            for (auto &[k, v] : cnt) {
                t += v;
            }
            res = max(res, t);
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
