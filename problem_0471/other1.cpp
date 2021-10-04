class Solution {
public:
    string encode_str(vector<vector<string>> &dp, string s, int i, int j)
    {
        int size = j - i + 1;

        for (int len = 1; len <= size/2; len++) {
            bool repeat = true;
            string match = s.substr(i, len);

            if (size % len != 0)
                continue;

            for (int k = i + len; k < i + size; k += len) {
                string current = s.substr(k, len);

                if (match != current) {
                    repeat = false;
                    break;
                }
            }
            if (repeat)
                return to_string(size/len) + '[' + dp[i][i+len - 1] + ']';
        }
        return s.substr(i, size);
    }

    string encode(string s) {
        int N = s.size();
        vector<vector<string>> dp(N, vector<string>(N));

        if (s.size() < 4)
            return s;

        for (int i = 0; i < N; i++)
            dp[i][i] = s[i];

        for (int i = N - 2; i>= 0; i--) {
            for (int j = i+1; j < N; j++) {
                dp[i][j] = encode_str(dp, s, i, j);
                for (int k = i+1; k < j; k++) {
                    if (dp[i][j].size() > dp[i][k].size() + dp[k+1][j].size())
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                }
            }
        }

        return dp[0][N-1];
    }
};
