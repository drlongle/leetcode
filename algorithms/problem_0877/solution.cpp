/*
877. Stone Game
Medium

Alex and Lee play a game with piles of stones. There are an even number of piles arranged in a row, and each pile
has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from
either the beginning or the end of the row.  This continues until there are no more piles left, at which point
the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

Example 1:
Input: piles = [5,3,4,5]
Output: true
Explanation:
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

Constraints:
2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.
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
    int get(vector<int>& piles, int sid, int eid) {
        if (sid == eid)
            return piles[sid];
        int& res = dp[sid][eid];
        if (res > 0)
            return res;
        res = max(piles[sid] + prefix[eid] - prefix[sid] - get(piles, sid+1, eid),
                  piles[eid] + prefix[eid-1] - (sid > 0 ? prefix[sid-1] : 0) - get(piles, sid, eid-1));
        return res;
    }

    vector<vector<int>> dp;
    vector<int> prefix;

    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int sz = piles.size();
        dp.resize(sz, vector<int>(sz, -1));
        partial_sum(piles.begin(), piles.end(), back_inserter(prefix));

        int sum = get(piles, 0, sz-1);
        return sum > total / 2;
    }
};

int main() {
    vector<int> piles;

    {
        Solution sol;
        piles = {5,3,4,5};
        cout << boolalpha << sol.stoneGame(piles) << endl;
    }

    return 0;
}
