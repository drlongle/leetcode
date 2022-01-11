class Solution {
public:
    
    // Corner cases:
    // 1. The leading '0's, e.g. "000001"
    // 2. The '0's in the middle needs special handling
    int numDecodings(string s) {
        
        // Handle the leading '0's
        if(s.empty() || s[0] == '0')  return 0;
        
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 1; i < s.size(); i ++) {
            int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
            
            // Handle cases with 2 potential decoding ways e.g. "12"
            if(val <= 26 & val >= 10) dp[i + 1] += dp[i - 1];
            
            // Handle cases like "10" or "20"
            if(s[i] != '0') dp[i + 1] += dp[i];
            
            // Handling illegal cases like "32", "27" etc
            if(dp[i + 1] == 0)  return 0;
        }
        
        return dp[s.size()];
    }
};

