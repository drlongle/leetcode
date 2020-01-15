/*
dp[i][j] = k stands for two sub strings that start from text[i] and text[j] respectively, are same to at most k characters.
Let's say we've known string s1 starting from i+1 and string s2 starting from j+1 are identical up to dp[i+1][j+1] characters. So for string s1' and s2' starting from i and j position, if ch[i] != ch[j] then this number becomes 0, otherwise we added this current one into account. and recurrence backward until dp table is all computed.

dp[i][j]=dp[i+1][j+1]
The critical condition for this question is when i +k == j, which means these two strings are "concatenated" together without any other character. A little debug actually fix that condition to j-i <= dp[i][j] = k as strings are still valid but k could be greater than j-i.
 */
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        if (text.size() <= 1) return 0;
        int N = text.size();
        // dp[i][j] = k means strcmp (text.data () + i, text.data() + j, k) == 0
        vector<vector<int>> dp (N + 1, vector<int> (N + 1, 0));
        unordered_set<string> res;
        auto &ch = text;
        for (int j = N-1; j > 0; j--) {
            for (int i = j-1; i >= 0; i--) {
                dp[i][j] = ch[i] == ch[j] ? 1 + dp[i+1][j+1] : 0;
                if (dp[i][j] >= j-i) {
                    res.insert ( ch.substr(i, j-i)); 
                }
            }
        }
        return res.size();
    }
};
