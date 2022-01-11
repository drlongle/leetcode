/*
1690. Stone Game VII
Medium

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the
rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row.
The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize
the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left,
return the difference in Alice and Bob's score if they both play optimally.

Example 1:
Input: stones = [5,3,1,4,2]
Output: 6
Explanation:
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.

Example 2:
Input: stones = [7,90,5,1,100,10,10,2]
Output: 122

Constraints:
n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> prefix{0};
    vector<vector<int>> dp;

    int compute(vector<int>& stones, int i, int j) {
        if (i >= j)
            return 0;
        auto& res = dp[i][j];
        if (res >= 0) {
            return res;
        }

        int r1 = prefix[j+1] - prefix[i+1] - compute(stones, i+1, j); // eliminate the i-th stone
        int r2 = prefix[j] - prefix[i] - compute(stones, i, j-1); // eliminate the j-th stone
        return res = max(r1, r2);
    }

    int stoneGameVII(vector<int>& stones) {
        partial_sum(begin(stones), end(stones), back_inserter(prefix));
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        return compute(stones, 0, n-1);
    }
};

int main() {
    vector<int> stones;

    // Output: 6
    {
        Solution sol;
        stones = {5,3,1,4,2};
        cout << sol.stoneGameVII(stones) << endl;
    }

    // Output: 122
    {
        Solution sol;
        stones = {7,90,5,1,100,10,10,2};
        cout << sol.stoneGameVII(stones) << endl;
    }

    return 0;
}
