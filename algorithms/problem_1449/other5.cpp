class Solution {
    bool isGreaterThan(string &a, string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;
            return a[i] > b[i];
        }
        return false;
    }
public:
    string largestNumber(vector<int>& A, int T) {
        int N = A.size();
        vector<string> dp(T + 1, "0");
        dp[0] = "";
        for (int i = 0; i < N; ++i) {
            for (int c = 1; c <= T; ++c) {
                if (c < A[i] || dp[c - A[i]] == "0") continue;
                auto s = string(1, '1' + i) + dp[c - A[i]];
                if (isGreaterThan(s, dp[c])) dp[c] = s;
            }
        }
        return dp[T];
    }
};
