/*
1301. Number of Paths with Max Score
Hard

You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

Example 1:
Input: board = ["E23","2X2","12S"]
Output: [7,1]

Example 2:
Input: board = ["E12","1X1","21S"]
Output: [4,2]

Example 3:
Input: board = ["E11","XXX","11S"]
Output: [0,0]

Constraints:
2 <= board.length == board[i].length <= 100
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
    static constexpr int MOD = 1000000007;
    vector<vector<int>> offsets{{0, -1}, {-1, 0}, {-1, -1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>{0, 0}));
        dp[0][0] = {0, 1};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                char ch = board[i][j];
                if ((i == 0 && j == 0) || ch == 'X')
                    continue;
                map<int, int> count;
                for (auto& offset: offsets) {
                    int pi = i + offset[0];
                    int pj = j + offset[1];
                    if (pi >= 0 && pi < m && pj >= 0 && pj < n && dp[pi][pj][1] > 0) {
                        auto index = dp[pi][pj][0] + (ch >= '0' && ch <= '9' ? ch - '0' : 0);
                        count[index] = (count[index] + dp[pi][pj][1]) % MOD;
                    }
                }
                if (count.size()) {
                    auto it = count.rbegin();
                    dp[i][j] = {it->first, it->second};
                }
            }
        
        return dp[m-1][n-1];;
    }
};

int main() {
    Solution sol;
    vector<string> board;

    // Output: {7,1}
    board = {"E23", "2X2", "12S"};

    // Output: {4,2}
    // board = {"E12", "1X1", "21S"};

    // Output: {0,0}
    // board = {"E11","XXX","11S"};

    auto res = sol.pathsWithMaxScore(board);
    cout << "Result: " << res[0] << ", " << res[1] << endl;

    return 0;
}
