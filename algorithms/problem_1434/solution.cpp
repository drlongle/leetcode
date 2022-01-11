/*
1434. Number of Ways to Wear Different Hats to Each Other
Hard

There are n people and 40 types of hats labeled from 1 to 40.
Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.
Return the number of ways that the n people wear different hats to each other.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.

Example 2:
Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)

Example 3:
Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.

Example 4:
Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
Output: 111

Constraints:
n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] contains a list of unique integers.
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
    using BS = bitset<11>;
    
    static constexpr int MOD = 1000000007;
    int sz;
    
    int dfs(BS curr, int level) {
        if (curr.count() == sz) {
            return 1;
        } else if (level > 40)
            return 0;

        auto it = dp[level].find(curr);
        if (it != dp[level].end())
            return it->second;
        
        int sum = dfs(curr, level+1);
        for (int i = 0; i <= sz; ++i) {
            if (!Hats[level].test(i) || curr.test(i))
                continue;
            curr.set(i);
            sum = (sum + dfs(curr, level+1)) % MOD;
            curr.reset(i);
        }

        return dp[level][curr] = sum;
    }

    vector<unordered_map<BS, int>> dp;
    vector<BS> Hats;
    int numberWays(vector<vector<int>>& hats) {
        sz = hats.size();
        dp.resize(41);
        Hats.resize(41);
        for (int i = 0; i < sz; ++i) {
            for (int hat: hats[i]) {
                Hats[hat].set(i);
            }
        }

        return dfs(BS(), 0);
    }
};

int main() {

    vector<vector<int>> hats;

    // Output: 1
    {
        Solution sol;
        hats = {{3,4},{4,5},{5}};
        cout << sol.numberWays(hats) << endl;
    }
  
    // Output: 4
    {
        Solution sol;
        hats = {{3,5,1},{3,5}};
        cout << sol.numberWays(hats) << endl;
    }
  
    // Output: 24
    {
        Solution sol;
        hats = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
        cout << sol.numberWays(hats) << endl;
    }
  
    // Output: 111
    {
        Solution sol;
        hats = {{1,2,3},{2,3,5,6},{1,3,7,9},{1,8,9},{2,5,7}};
        cout << sol.numberWays(hats) << endl;
    }

    // Output: 9497549
    {
        Solution sol;
        hats = {{4,15,16,26,28},{1,2,3,4,6,7,8,10,13,14,15,16,17,18,19,21,22,24,25,27,28,29,30},{1,2,3,4,5,7,9,10,11,12,14,15,17,18,19,20,21,22,23,24,25,28,29,30},{2,3,6,7,14,16,17,18,19,20,21,24,25,27,28,29},{1,10},{1,5,6,7,8,9,10,11,13,14,15,16,19,20,21,22,24,25,27,28},{2,5,10,14,16,19,21,22,23,27,30}};
        cout << sol.numberWays(hats) << endl;
    }

    // Output: 778256459
    {
        Solution sol;
        hats = {{1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25},{2,5,16},{1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25},{1,3,6,8,11,12,13,16,17,19,20,22,24,25},{11,12,14,16,18,24},{2,3,4,5,7,8,13,14,15,17,18,21,24},{1,2,6,7,10,11,13,14,16,18,19,21,23},{1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25},{2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25}};
        cout << sol.numberWays(hats) << endl;
    }

    // Output: 178121190
    {
        Solution sol;
        hats = {{2,6,8,9,10,11,16,17,19,21,23,25},{1,3,6,7,8,9,10,11,12,13,14,19,20,22,23,25},{1,3,4,6,7,8,10,12,13,15,16,17,19,20,22},{2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,19,20,23,25},{1,4,5,8,12,14,15,16,19,22,24,25},{1,2,3,4,7,8,9,11,12,13,16,17,18,19,22,24,25},{1,2,3,4,10,12,14,17,18,20,21,22,23,24},{2,14,17,22}};
        cout << sol.numberWays(hats) << endl;
    }

    // Output: 842465346
    {
        Solution sol;
        hats = {{1,3,5,10,12,13,14,15,16,18,19,20,21,27,34,35,38,39,40},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40},{3,7,10,12,13,14,15,17,21,25,29,31,35,40},{2,3,7,8,9,11,12,14,15,16,17,18,19,20,22,24,25,28,29,32,33,34,35,36,38},{6,12,17,20,22,26,28,30,31,32,34,35},{1,4,6,7,12,13,14,15,21,22,27,28,30,31,32,35,37,38,40},{6,12,21,25,38},{1,3,4,5,6,7,8,9,10,11,12,13,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,35,36,37,38,39,40}};
        cout << sol.numberWays(hats) << endl;
    }

    // Output: 384415842
    {
        Solution sol;
        hats = {{3,9,15,19,22,25,26,40},{1,4,6,7,9,10,12,15,17,19,20,21,25,27,28,31,33,34,37,38,39,40},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40},{2,4,5,6,7,8,10,11,12,14,15,17,18,21,23,24,30,31,32,33,34,35,38},{2,6,7,10,11,13,16,19,20,22,29,40},{10,16,20,26,28,40},{39},{6,7,11,12,15,18,21,22,24,32,35,39},{1,2,5,7,8,9,13,14,18,20,23,24,25,28,33,35,38,39},{8,10,16,20,21,23}};
        cout << sol.numberWays(hats) << endl;        
    }
    
    return 0;
}
