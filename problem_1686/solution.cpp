/*
1686. Stone Game VI
Medium

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones in a pile. On each player's turn, they can remove a stone from the pile and
receive points based on the stone's value. Alice and Bob may value the stones differently.

You are given two integer arrays of length n, aliceValues and bobValues. Each aliceValues[i] and
bobValues[i] represents how Alice and Bob, respectively, value the ith stone.

The winner is the person with the most points after all the stones are chosen. If both players
have the same amount of points, the game results in a draw. Both players will play optimally.

Determine the result of the game, and:
If Alice wins, return 1.
If Bob wins, return -1.
If the game results in a draw, return 0.

Example 1:
Input: aliceValues = [1,3], bobValues = [2,1]
Output: 1
Explanation:
If Alice takes stone 1 (0-indexed) first, Alice will receive 3 points.
Bob can only choose stone 0, and will only receive 2 points.
Alice wins.

Example 2:
Input: aliceValues = [1,2], bobValues = [3,1]
Output: 0
Explanation:
If Alice takes stone 0, and Bob takes stone 1, they will both have 1 point.
Draw.

Example 3:
Input: aliceValues = [2,4,3], bobValues = [1,6,7]
Output: -1
Explanation:
Regardless of how Alice plays, Bob will be able to have more points than Alice.
For example, if Alice takes stone 1, Bob can take stone 2, and Alice takes stone 0,
Alice will have 6 points to Bob's 7. Bob wins.

Constraints:
n == aliceValues.length == bobValues.length
1 <= n <= 105
1 <= aliceValues[i], bobValues[i] <= 100
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

#include "common/TreeNode.h"

using namespace std;

/*
Intuition
Sort stones by their sum value for Alice and Bob.
If a stone is super valued for Alice, Alice wants to take it.
If a stone is super valued for Bob, Alice also wants to take it.
Because she doesn't want Bob to take it.

Explanation
Here is more convinced explanation.
Assume a stone valued [a,b] for Alice and Bod.
Alice takes it, worth a for Alice,
Bob takes it, worth b for Bob,
we can also consider that it worth -b for Alice.
The difference will be a+b.
That's the reason why we need to sort based on a+b.
And Alice and Bob will take one most valued stone each turn.
 */

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> indices(n);
        iota(begin(indices), end(indices), 0);
        auto comp = [&] (auto i, auto j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        };
        sort(begin(indices), end(indices), comp);
        int alice = 0, bob = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                alice += aliceValues[indices[i]];
            else
                bob += bobValues[indices[i]];
        }

        if (alice > bob)
            return 1;
        else if (alice == bob)
            return 0;
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> aliceValues, bobValues;

    // Output: 1
    aliceValues = {1,3}, bobValues = {2,1};
    cout << sol.stoneGameVI(aliceValues, bobValues) << endl;

    // Output: 0
    aliceValues = {1,2}, bobValues = {3,1};
    cout << sol.stoneGameVI(aliceValues, bobValues) << endl;

    // Output: -1
    aliceValues = {2,4,3}, bobValues = {1,6,7};
    cout << sol.stoneGameVI(aliceValues, bobValues) << endl;

    return 0;
}
