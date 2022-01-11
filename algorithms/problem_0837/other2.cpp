class Solution {
public:
    double new21Game(int N, int K, int W) {
        /**
            f(i) = sum/W,  sum += f(i) - f(i-W)     if i > W
                 = (sum + W-(i-1))/W, sum += f(i)
            f(i) = 0, i < K-N
            f(i) = 1, K-N <= i <= 0
        **/
        int minN = N-K;
        vector<double> dp(K+1, 1.0);
        double sum = 0.0;
        for (int i = 1; i <= K; i++) {
            if (i <= W) {
                dp[i] = (sum + min(W-i, minN) + 1) / W;
                sum += dp[i];
            } else {
                dp[i] = sum / W;
                sum += dp[i] - dp[i-W];
            }
        }
        return dp[K];
    }
};
