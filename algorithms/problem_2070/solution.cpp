/*
2070. Most Beautiful Item for Each Query
Medium

You are given a 2D integer array items where items[i] = [pricei, beautyi]
denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you
want to determine the maximum beauty of an item whose price is less than or
equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the
answer to the jth query.

Example 1:
Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the
answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4].
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are
[1,2], [3,2], [2,4], and [3,5]. The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.

Example 2:
Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation:
The price of every item is equal to 1, so we choose the item with the maximum
beauty 4. Note that multiple items can have the same price and/or beauty.

Example 3:
Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.

Constraints:
1 <= items.length, queries.length <= 10^5
items[i].length == 2
1 <= pricei, beautyi, queries[j] <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bit>
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<int> maximumBeauty(vector<vector<int>> &items,
                              vector<int> &queries) {
        map<int, int> lookup;
        for (auto &i : items) {
            lookup[i[0]] = max(lookup[i[0]], i[1]);
        }

        int max_beauty = numeric_limits<int>::min();
        for (auto &[k, v] : lookup) {
            v = max(v, max_beauty);
            max_beauty = max(max_beauty, v);
        }

        vector<int> result;
        for (auto q : queries) {
            auto it = lookup.lower_bound(q);
            if (it->first == q)
                result.push_back(it->second);
            else if (it == lookup.begin()) {
                result.push_back(0);
            } else
                result.push_back((--it)->second);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items;
    vector<int> queries, result;

    // Output: [2,4,5,5,6,6]
    items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}},
    queries = {1, 2, 3, 4, 5, 6};
    result = sol.maximumBeauty(items, queries);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
