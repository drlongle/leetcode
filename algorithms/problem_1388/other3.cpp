/*
First, observe that there exists no solution where we can pick both slice 0 and slice n - 1, which means that we can split the circular problem into 2 linear problems where we once pick slices from [0 ... n - 2] and then from [1 ... n - 1] (inclusive)

Basically, we want to choose the best way of selecting n / 3 slices such that no 2 slices are adjacent. Now for each slice, either we pick it or we do not. If we don't pick it, we are free to pick the one before it, else we must discard the one before it.

Hence, dp[i][j] is the best way to pick j slices among slices from [0 ... i - 2] or [1 ... i - 1] (depending on which of the two linear solutions we are currently handling, which is why you see slices[i - 1 - !l] in the solution).
 */

class Solution {
private:
    int maxSizeSlices(const vector<int> &slices, int l) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int>(n / 3 + 1, 0));
        
        for(int i = 2; i < n + 1; i++)
            for(int j = 1; j <= n / 3; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i - 1 - !l]);
       
        return dp[n][n / 3];
    }
    
public:
    int maxSizeSlices(const vector<int>& slices) {
        return max(maxSizeSlices(slices, 0), maxSizeSlices(slices, 1));
    }
};
