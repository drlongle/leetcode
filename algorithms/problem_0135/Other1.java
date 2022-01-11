class Solution {

public int candy(int[] ratings) {
    int length = ratings.length;
    if(length == 0) return 0;

    int[] dp = new int[length]; // dp[i] indicates number of consecutive smaller elements on right side of i
    dp[length-1] = 0;
    for(int i=length-2; i>=0; i--) { 
        if (ratings[i] > ratings[i+1]) dp[i] = dp[i+1]+1;
        else dp[i] = 0;
    }
    
    int currC = dp[0] + 1;
    int pre = currC; // stores left children candy 
    int totalC = currC;
    for(int i=1; i<length; i++) {
        if (ratings[i] <= ratings[i-1]) currC = dp[i] + 1; // if less, then we just add 1 to dp[i]
        else currC = Math.max(pre, dp[i]) + 1; // if more, then we add 1 to max of (pre, dp[i])
        
        totalC += currC;
        pre = currC;
    }
    
    return totalC;
}
}


