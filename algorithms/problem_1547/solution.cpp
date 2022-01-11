/*
1547. Minimum Cost to Cut a Stick
Hard

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6
is labelled as follows.

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut
a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the
cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the
second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The
total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the
example photo 7 + 4 + 3 + 2 = 16).

Example 2:
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which
is the minimum possible.

Constraints:
2 <= n <= 10^6
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pieces, prefix;
    int merge(int begin, int end) {
        int& res = dp[begin][end];
        if (res >= 0)
            return res;
        if (begin == end)
            return res = 0;
        res = numeric_limits<int>::max();
        for (int i = begin; i < end; ++i) {
            res = min(res, merge(begin, i) + merge(i+1, end));
        }
        res += prefix[end] - ((begin > 0) ? prefix[begin-1] : 0);

        return res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));

        int last_cut = 0;
        for (int cut: cuts) {
            pieces.push_back(cut - last_cut);
            last_cut = cut;
        }
        pieces.push_back(n - last_cut);
        partial_sum(begin(pieces), end(pieces), back_inserter(prefix));

        int sz = pieces.size();
        dp.resize(sz, vector<int>(sz, -1));

        return merge(0, sz-1);
    }
};

int main() {
    vector<int> cuts;
    int n;

    // Output: 16
    {
        Solution sol;
        n = 7, cuts = {1, 3, 4, 5};
        cout << sol.minCost(n, cuts) << endl;
    }

    // Output: 22
    {
        Solution sol;
        n = 9, cuts = {5, 6, 1, 4, 2};
        cout << sol.minCost(n, cuts) << endl;
    }

    // Output: 150
    {
        Solution sol;
        n = 36, cuts = {13, 17, 15, 18, 3, 22, 27, 6, 35, 7, 11, 28, 26, 20, 4, 5, 21, 10, 8};
        cout << sol.minCost(n, cuts) << endl;
    }

    return 0;
}
