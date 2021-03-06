/*
The idea is to try all possible pair of masks for each adjacent rows which satisfy our constraints and find the best answer possible.
*/
class Solution {
public:
    
    //O(n * m * 2^2m)
    int solve(int r, int mask, vector<vector<int>>& dp, vector<vector<char>>& seats) {
        if(r < 0) return 0;
        if(dp[r][mask] != -1)
            return dp[r][mask];
        
        int res = 0;
        int cols = (int) seats[0].size();
        
        for(int m = 0; m < 1 << cols; ++m) {
            bool ok = 1;
            for(int i = 0; i < cols; ++i) {
                if(m & (1 << i)) {
                    if(seats[r][i] == '#') {
                        ok = 0;
                        break;
                    }
                    if(i < cols - 1 && (m & (1 << (i + 1)))) {
                        ok = 0;
                        break;
                    }
                    if(i > 0 && (mask & (1 << (i - 1)))) {
                        ok = 0;
                        break;
                    }
                    if(i < cols - 1 && (mask & (1 << (i + 1)))) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) {
                res = max(res, __builtin_popcount(m) + solve(r - 1, m, dp, seats));
            }
        }
        return dp[r][mask] = res;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int rows = (int) seats.size();
        int cols = (int) seats[0].size();
        vector<vector<int>> dp(rows, vector<int>(1 << cols, -1));
        int ans = 0;
        for(int mask = 0; mask < 1 << cols; ++mask) {
            bool ok = 1;
            for(int i = 0; i < cols; ++i) {
                if(mask & (1 << i)) {
                    if(seats[rows - 1][i] == '#') {
                        ok = 0;
                        break;
                    }
                    if(i < cols - 1 && (mask & (1 << (i + 1)))) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) {
                ans = max(ans, __builtin_popcount(mask) + solve(rows - 2, mask, dp, seats));
            }
        }
        return ans;
    }
};
