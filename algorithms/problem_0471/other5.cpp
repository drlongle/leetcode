class Solution {
public:
    string encode(const string& s) {
        if(s.size() < 4) return s;
        int size{(int)s.size()};
        std::vector<std::vector<string>> dp(size+1, std::vector<string>(size+1, ""));
        for(int i{0}; i < size; ++i) dp[i][i+1] = s[i];
        for(int i{size-2}; i >= 0; --i) {
            for(int j{i+2}; j <= size; ++j) {
                dp[i][j] = encode(dp, s, i, j);
                for(int k{i}; k <= j; ++k)
                    if(dp[i][j].size() > dp[i][k].size() + dp[k][j].size())
                        dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
        return dp[0][size];
    }
    string encode(const std::vector<std::vector<string>>& dp, const string& s, int i, int j) {
        for(int k{1}, len{j-i}, stop{(j-i)/2}; k <= stop; ++k) {
            if(len % k) continue;
            bool valid{true};
            for(int l{i}, n{0}; l < j; ++l, ++n) {
                if(s[i+n%k] != s[l]) {
                    valid = false;
                    break;
                }
            }
            // Need extra check here if encoding of same length is unwanted
            if(valid) return to_string(len/k)+'[' + dp[i][i+k] + ']';
        }
        return s.substr(i, j-i);
    }
};
