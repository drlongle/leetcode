class Solution {
  public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 3;
        }
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;

        // initial conditions

        for (int i = 4; i <= n; i++) {
            dp[i] = i;
            if (i % 2 == 0)
                dp[i] =
                    min(dp[i],
                        2 + dp[i / 2]); // 2 is lowest factor for an even number

            else {
                for (int num = 2; num < i; num++) {
                    if (i % num == 0) {
                        dp[i] =
                            min(dp[i],
                                dp[i / num] + num); //  the lowest factor is the
                                                    //  answer so just break.
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
