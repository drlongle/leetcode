class Solution {
    private int[] memo;

    public int numWays(int n, int k) {
        if (n == 0) return 0;
        memo = new int[n + 1];
        return totalWays(n, k);
    }

    private int totalWays(int posts, int k) {
        if (posts == 1) return k;
        if (posts == 2) return k * k;
        if (memo[posts - 1] == 0) {
            memo[posts - 1] = totalWays(posts - 1, k);
        }
        if (memo[posts - 2] == 0) {
            memo[posts - 2] = totalWays(posts - 2, k);
        }
        memo[posts] = (memo[posts - 1] + memo[posts - 2]) * (k - 1);
        return memo[posts];
    }
}
