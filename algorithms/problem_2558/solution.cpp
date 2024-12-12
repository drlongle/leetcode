/*
2558. Take Gifts From the Richest Pile
Easy

You are given an integer array gifts denoting the number of gifts in various
piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile.
Take the rest of the gifts. Return the number of gifts remaining after k
seconds.

Example 1:
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts
remaining is 29.

Example 2:
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift
in each pile. That is, you can't take any pile with you. So, the total gifts
remaining are 4.

Constraints:
1 <= gifts.length <= 10^3
1 <= gifts[i] <= 10^9
1 <= k <= 10^3
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
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue pq(gifts.begin(), gifts.end());
        long long res = accumulate(gifts.begin(), gifts.end(), 0ull);

        for (int i = 0; i < k; ++i) {
            int v{pq.top()};
            int nv = sqrt(v);
            res -= v - nv;
            pq.pop();
            pq.emplace(nv);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> gifts;
    int k;

    gifts = {25, 64, 9, 4, 100}, k = 4;
    cout << sol.pickGifts(gifts, k) << endl;

    return 0;
}
