/*
656. Coin Path
Hard

You are given an integer array coins (1-indexed) of length n and an integer maxJump. You can jump to any index i of the
array coins if coins[i] != -1 and you have to pay coins[i] when you visit index i. In addition to that, if you are
currently at index i, you can only jump to any index i + k where i + k <= n and k is a value in the range [1, maxJump].

You are initially positioned at index 1 (coins[1] is not -1). You want to find the path that reaches index n with the
minimum cost.

Return an integer array of the indices that you will visit in order so that you can reach index n with the minimum cost.
If there are multiple paths with the same cost, return the lexicographically smallest such path. If it is not possible
to reach index n, return an empty array.

A path p1 = [Pa1, Pa2, ..., Pax] of length x is lexicographically smaller than p2 = [Pb1, Pb2, ..., Pbx] of length y,
if and only if at the first j where Paj and Pbj differ, Paj < Pbj; when no such j exists, then x < y.

Example 1:
Input: coins = [1,2,4,-1,2], maxJump = 2
Output: [1,3,5]

Example 2:
Input: coins = [1,2,4,-1,2], maxJump = 1
Output: []

Constraints:
1 <= coins.length <= 1000
-1 <= coins[i] <= 100
coins[1] != -1
1 <= maxJump <= 100
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

    vector<int> dp, next;
    int n, MAX = 1000000;

    int visit(vector<int>& coins, int index, int maxJump) {
        if (index == n - 1)
            return 0;
        int& res = dp[index];
        if (res < 0 || coins[index] < 0) {
            return -1;
        }
        if (res != MAX)
            return res;
        for (int i = 1; i < min(maxJump + 1, n - index); ++i) {
            int j = i + index;
            if (coins[j] < 0)
                continue;
            int t = visit(coins, j, maxJump);
            if (t < 0 || t == MAX)
                continue;
            t += coins[j];
            if (t < res) {
                res = t;
                next[index] = j;
            }
        }
        if (res == MAX)
            res = -1;

        return res;
    }

    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        n = coins.size();
        dp.resize(n, MAX);
        next.resize(n, -1);
        int res = visit(coins, 0, maxJump);
        if (res < 0|| res == MAX)
            return {};
        vector<int> path;
        int i = 0;
        while (true) {
            path.push_back(i + 1);
            if (i == n - 1)
                break;
            i = next[i];
        }
        return path;
    }
};

int main() {
    Solution sol;

    return 0;
}
