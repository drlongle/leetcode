/** dp[m+1][n+1] m is length of s1, n is length of s2
 *  dp[i][j] means the prev i+j characters of s3 can be formed by interleaving of the prev i character of s1, and j charcter of s2;
 *  initialization dp[0][0] = true; dp[i][0] == dp[i-1][0] && (s1.charAt(i-1) == s3.charAt(i-1)); dp[0][j] == dp[0][j-1] && (s2.charAt(j-1) == s3.charAt(j-1));
 *  update dp[i][j] = true only if dp[i-1][j] == true & s1[i-1] == s3[i+j-1] or dp[i][j-1] = true; s2[j-1] = s3[i+j-1]
 *  return dp[m][n]
 */

class Solution {
    public static boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null && s2 == null) return s3 == null;
        if (s1 == null) return s2.equals(s3);
        if (s2 == null) return s1.equals(s3);
        if (s1.length() + s2.length() != s3.length()) return false;
        int m = s1.length(), n = s2.length();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && (s1.charAt(i-1) == s3.charAt(i-1));
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && (s2.charAt(j-1) == s3.charAt(j-1));
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i][j-1] && (s2.charAt(j-1) == s3.charAt(i+j-1))
                    ||dp[i-1][j] && (s1.charAt(i-1) == s3.charAt(i+j-1)));
            }
        }
        return dp[m][n];
    }
}
