/*
1140. Stone Game II
Medium

Alex and Lee continue their games with piles of stones.  There are a number of piles arranged
in a row, and each pile has a positive integer number of stones piles[i]. The objective of
the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles,
where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes
2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the
beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles
in total. So we return 10 since it's larger.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int stoneGame(vector<int>& piles, int begin, int M) {
        if (begin >= nsize)
            return 0;
        int accu = accumulate(piles.begin()+begin, piles.end(), 0);
        if (begin + 2*M >= nsize)
            return accu;
        auto it = dp[begin].find(M);
        if (it != dp[begin].end())
            return it->second;
        int res = 0;
        for (int x = 1; x <= 2*M && begin + x <= nsize; ++x) {
            res = max(res, accu - stoneGame(piles, begin+x, max(x, M)));
        }

        dp[begin][M] = res;
        return res;
    }
    
    int nsize;
    vector<map<int, int>> dp;
    
    int stoneGameII(vector<int>& piles) {
        nsize = piles.size();
        dp.resize(nsize);
        return stoneGame(piles, 0, 1);
    }
};

int main()
{
    Solution sol;
    vector<int> piles;

    // Expected: 10
    piles = {2,7,9,4,4};

    // 3 / 21 test cases passed.
    // Expected: 104
    piles = {1,2,3,4,5,100};

    // 6 / 21 test cases passed.
    // Expected: 29
    piles = {9,2,2,8,3,7,9,9};

    // 11 / 21 test cases passed.
    // Expected: 56
    piles = {8,9,5,4,5,4,1,1,9,3,1,10,5,9,6,2,7,6,6,9};
    
    cout << "Result: " << sol.stoneGameII(piles) << endl;
    
    return 0;
}

