/*
i = start index of s1;
j = start index of s2;
dp[i][j] = minimum lengh of contiguous substring part of s1[i:], so that s2[j:] is a subsequence of the part.

TC: O(m*n)
SC: O(m*n)
*/

class Solution {
public:
    string minWindow(string s1, string s2) {
        if (s2.size() > s1.size()) return "";

        vector<int> dp[s1.size()];
        for (int i = 0; i < s1.size(); i++)
            dp[i].resize(s2.size(), -1);

        dfs(s1, s2, 0, 0, dp);

        int chosen = -1;
        int minl = 1e5;
        for (int i = 0; i < s1.size(); i++){
            if (dp[i][0] > 0 && dp[i][0] < minl) {
                chosen = i;
                minl = dp[i][0];
            }
        }

        return chosen==-1 || minl >= 1e5? "" : s1.substr(chosen, minl);
    }

    int dfs(string& s1, string& s2, int i, int j, vector<int> dp[]){
        if (j == s2.size()) return 0;

        if (s1.size()-i < s2.size()-j) return 1e5;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] != s2[j]) return dp[i][j] = 1+dfs(s1, s2, i+1, j, dp);

        return dp[i][j] = 1+min(dfs(s1, s2, i+1, j, dp), dfs(s1, s2, i+1, j+1, dp));
    }
};
