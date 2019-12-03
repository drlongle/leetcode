class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        vector<int> dp = {0, 0, 0}, dp2;
        for (int a : A) {
            dp2 = dp;
            for (int i: dp2) {
                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
            }
        }
        return dp[0];
    }
};
