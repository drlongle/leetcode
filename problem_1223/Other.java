class Solution {
    int[][][] dp = new int[5000][6][16];
    final int M = 1000000007;
    
    public int dieSimulator(int n, int[] rollMax) {
        return dfs(n, rollMax, -1, 0);
    }
    
    private int dfs(int dieLeft, int[] rollMax, int last, int curlen){
        if(dieLeft == 0) return 1;
        if(last >= 0 && dp[dieLeft][last][curlen] > 0) return dp[dieLeft][last][curlen];
        int ans = 0;
        for(int i=0; i<6; i++){
            if(i == last && curlen == rollMax[i]) continue;
            ans = (ans + dfs(dieLeft - 1, rollMax, i, i == last ? curlen + 1 : 1)) % M;
        }
        if(last >= 0) dp[dieLeft][last][curlen] = ans;
        return ans;
    }
}
