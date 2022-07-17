class Solution {
  public:
    // give score to each character that is equal to the maximum length of
    // substring present in s that ends with that character
    int findSubstringInWraproundString(string p) {
        int dp[26] = {}, l = p.length(), curr = 1;
        // an array to store the score of each character
        for (int i = 0; i < l; i++) {
            curr = (i > 0 && ((p[i - 1] + 1) % 26) == p[i] % 26) ? curr + 1 : 1;
            dp[p[i] - 97] = max(dp[p[i] - 97], curr);
        }
        return accumulate(dp, dp + 26, 0);
    }
};
