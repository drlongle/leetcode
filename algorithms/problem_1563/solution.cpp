/*
1563. Stone Game V
Hard

There are several stones arranged in a row, and each stone has an associated value which is an integer given
in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row),
then Bob calculates the value of each row which is the sum of the values of all the stones in this row.
Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row.
If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round
starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.

Return the maximum score that Alice can obtain.

Example 1:
Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the
right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score
becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and
Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

Example 2:
Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28

Example 3:
Input: stoneValue = [4]
Output: 0

Constraints:
1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6
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
    vector<int> prefix;
    int get(int sid, int eid) {
        if (sid == eid)
            return 0;
        int& res = dp[sid][eid];
        if (res >= 0)
            return res;

        for (int i = sid; i < eid; ++i) {
            int lsum = prefix[i] - (sid > 0 ? prefix[sid-1] : 0);
            int rsum = prefix[eid] - prefix[i];
            if (lsum > rsum)
                res = max(res, rsum + get(i+1, eid));
            else if (lsum < rsum)
                res = max(res, lsum + get(sid, i));
            else
                res = max({res, lsum + get(sid, i), rsum + get(i+1, eid)});
        }

        return res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int sz = stoneValue.size();
        dp.resize(sz, vector<int>(sz, -1));
        partial_sum(begin(stoneValue), end(stoneValue), back_inserter(prefix));

        return get(0, sz-1);
    }
};

int main() {
    vector<int> stoneValue;

    // Output: 18
    {
        Solution sol;
        stoneValue = {6,2,3,4,5,5};
        cout << sol.stoneGameV(stoneValue) << endl;
    }

    // Output: 28
    {
        Solution sol;
        stoneValue = {7,7,7,7,7,7,7};
        cout << sol.stoneGameV(stoneValue) << endl;
    }

    // Output: 0
    {
        Solution sol;
        stoneValue = {4};
        cout << sol.stoneGameV(stoneValue) << endl;
    }

    return 0;
}
