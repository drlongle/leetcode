class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        vector<int>dp(s2.length()+1,0);
        for(int i = 0; i<=s1.length();i++)
            for(int j = 0; j<=s2.length();j++)
                dp[j] =  (i>0 && s1[i-1] == s3[i+j-1] && dp[j] ) || (j>0 && s2[j-1] == s3[i+j-1] && dp[j-1]) || (i==0 && j==0);
        return dp[s2.length()];
    }
};

