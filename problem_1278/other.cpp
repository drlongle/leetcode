class Solution {
    int changesToPalindrome(const string& s, int i, int j) {
        int count = 0;
        for(; i < j; ++i, --j)
            if (s[i] != s[j])
                ++count;
        return count;
    }
    
    int find(const string& s, int idx, int k, vector<vector<int>>& dp) {
        if (dp[idx][k] > -1) return dp[idx][k];
        if (k == 1) return dp[idx][k] = changesToPalindrome(s, 0, idx);
        int minVal = INT_MAX;
        for (int i = idx - 1; i + 1 >= k - 1; --i)
            minVal = min(minVal, find(s, i, k - 1, dp) + changesToPalindrome(s, i + 1, idx));
        return dp[idx][k] = minVal;
    }
    
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, -1));
        return find(s, s.size() - 1, k, dp);
    }
};
