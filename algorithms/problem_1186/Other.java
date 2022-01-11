class Solution {
    public int maximumSum(int[] arr) {
        int [] dp1 = new int[arr.length]; //maximum subarray ending at i
        int [] dp2 = new int[arr.length]; //maximum subarray ending at i including a deletion
        
        int sol = Integer.MIN_VALUE;
        dp1[0] = arr[0];
        dp2[0] = 0; 
        sol = dp1[0];
        
        for(int i = 1; i < arr.length; ++i){
            dp1[i] = Math.max(arr[i], arr[i] + dp1[i - 1]);
            dp2[i] = Math.max(dp1[i - 1], dp2[i - 1] + arr[i]);
            sol = Math.max(sol, Math.max(dp1[i], dp2[i]));
        }
        
        return sol;
    }
}
