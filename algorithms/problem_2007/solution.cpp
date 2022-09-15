/*
2007. Find Original Array From Doubled Array
Medium

An integer array original is transformed into a doubled array changed by
appending twice the value of every element in original, and then randomly
shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If
changed is not a doubled array, return an empty array. The elements in original
may be returned in any order.

Example 1:
Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].

Example 2:
Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.

Example 3:
Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.

Constraints:
1 <= changed.length <= 10^5
0 <= changed[i] <= 10^5
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
    vector<int> findOriginalArray(vector<int> &changed) {
        map<int, int> count;
        for (int c : changed)
            ++count[c];
        vector<int> res;
        for (auto [k, v] : count) {
            if (v > 0) {
                if (k == 0) {
                    if (v % 2 != 0) {
                        res.clear();
                        break;
                    }
                    v /= 2;
                    count[k] -= v;
                }
                int doubled = 2 * k;
                count[doubled] -= v;
                if (count[doubled] < 0) {
                    res.clear();
                    break;
                }
                for (int i = 0; i < v; ++i)
                    res.push_back(k);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> changed, res;

    changed = {1, 3, 4, 2, 6, 8};
    res = sol.findOriginalArray(changed);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    changed = {0};
    res = sol.findOriginalArray(changed);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
