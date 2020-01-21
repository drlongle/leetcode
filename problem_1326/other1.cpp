/*
dp[i] is the minimum number of taps to water [0, i].
Initialize dp[i] with max = n + 2
dp[0] = [0] as we need no tap to water nothing.

Find the leftmost point of garden to water with tap i.
Find the rightmost point of garden to water with tap i.
We can water [left, right] with onr tap,
and water [0, left - 1] with dp[left - 1] taps.
 */

class Solution {
public:
    int minTaps(int n, vector<int>& A) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = max(i - A[i] + 1, 0); j <= min(i + A[i], n); ++j)
                dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
        return dp[n]  < n + 2 ? dp[n] : -1;
    }
};
