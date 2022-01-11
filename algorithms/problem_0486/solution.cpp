/*
486. Predict the Winner
Medium

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.

Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
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
#include <memory>
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
    vector<vector<int>> dp;
    int sum(vector<int>&nums, int i, int j) {
        if (i > j)
            return 0;
        //cout << i << ", " << j << endl;
        int res = dp[i][j];
        if (res >= 0)
            return res;
        res = nums[i] + min(sum(nums, i+2, j), sum(nums, i+1, j-1));
        res = max(res, nums[j] + min(sum(nums, i, j-2), sum(nums, i+1, j-1)));
        return dp[i][j] = res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sz = nums.size();
        dp.resize(sz, vector<int>(sz, -1));
        int acc = accumulate(begin(nums), end(nums), 0);
        int s = sum(nums, 0, sz-1);
        return s >= acc -s;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: False
    nums = {1, 5, 2};
    cout << boolalpha << sol.PredictTheWinner(nums) << endl;
    
    // Output: True
    nums = {1, 5, 233, 7};
    //cout << boolalpha << sol.PredictTheWinner(nums) << endl;
    
    return 0;
}
