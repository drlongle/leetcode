/*
1411. Number of Ways to Paint N × 3 Grid
Hard

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:
Input: n = 2
Output: 54

Example 3:
Input: n = 3
Output: 246

Example 4:
Input: n = 7
Output: 106494

Example 5:
Input: n = 5000
Output: 30228214

Constraints:
n == grid.length
grid[i].length == 3
1 <= n <= 5000
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    int numOfWays(int n) {
        constexpr int MOD = 1000000007;
        ll sandwich = 6; // two-color scheme like (Red, Green, Red)
        ll diverse = 6; // three-color scheme like (Red, Green, Yellow)
        for (int k = 2; k <= n; ++k) {
            auto ns = (3*sandwich + 2*diverse) % MOD;
            auto nd = (2*sandwich + 2*diverse) % MOD;            
            sandwich = ns;
            diverse = nd;
        }

        return (sandwich + diverse) % MOD;
    }
};

int main() {
    Solution sol;
    
    for (int n : {1,2,3,7,5000})
        cout << n << " -> " << sol.numOfWays(n) << endl;

    return 0;
}
