/*
1197. Minimum Knight Moves
Medium

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

Example 1:
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]

Example 2:
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    map<int, map<int, int>> dp;
    int minKnightMoves(int x, int y) {
        static vector<vector<int>> lookup{{0, 3, 2}, {3, 2, 1}, {2, 1, 4}};
        x = abs(x);
        y = abs(y);
        if (x <= 2 && y <= 2)
            return lookup[x][y];
        if (x < y)
            swap(x, y);

        int res;
        if (dp[x].count(y) != 0)
            return dp[x][y];

        res = 1 + min(minKnightMoves(x-2, y-1), minKnightMoves(x-1, y-2));
        dp[x][y] = res;

        return res;
    }
};

int main() {
    Solution sol;
    int x, y;

    // Output: 4
    x = 5, y = 5;
    
    // Output: 8
    //x = 10, y = 10;

    // Output: 14
    //x = 20, y = 20;

    // Output: 10
    //x = 20, y = 0;

    // Output: 100
    x = 200, y = 0;

    // Output: 56
    x = 2, y = 112;

    // Output: 72
    x = 130, y = -86;
    
    cout << "Result: " << sol.minKnightMoves(x, y) << endl;
    
    return 0;
}
