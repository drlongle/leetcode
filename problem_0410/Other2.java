
class Solution {
    public int splitArray(int[] nums, int m) {
        long[] dp = new long[nums.length+1];
    int L = nums.length;
    long[] S = new long[L+1];
    S[0]=0;
        dp[0] = Integer.MAX_VALUE;
    for(int i=0; i<L; i++){
        S[i+1] = S[i]+nums[i];
        dp[i+1] = S[i+1];
    }
        for(int i = 2;i<m+1;i++) {
            for(int j = dp.length-1;j>=0;j--) {
                for(int k =0; k<j;k++){
                dp[j] = Math.min(dp[j], Math.max(dp[j-k],S[j]-S[j-k]));
                }
        }
        }
        return Math.toIntExact(dp[nums.length]);
    }
}


