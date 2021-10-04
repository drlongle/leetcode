class Solution {
public:
    string encode(string s) {
        int size = s.size();
        if (size <= 4) {
            return s;
        }
        // dp[start][len] stores the shortest encoded substring s.substr(start, len) of s
        vector<vector<string>> dp;
        for (int i = 0; i < size; i++) {
            dp.push_back(vector<string>(size - i + 1, ""));
        }
        // dp[0][size] is the result, the recurrence is
        // dp[0][size] = min(dp[0][len] + dp[len][size - len])
        // for every len >= 1 and len <= size - 1
        for (int len = 1; len <= size; len++) {
            for (int start = 0; start <= size - len; start++) {
                string shortest = s.substr(start, len);
                if (len <= 4) {
                    dp[start][len] = shortest;
                    continue;
                }
                // if shortest = "abcdeabcde", shortest + shortest = "abcdeabcdeabcdeabcde"
                // repeatIndex = 5
                int repeatIndex = (shortest + shortest).find(shortest, 1);
                // the current substring contains repeat pattern
                // and the encoded string is shorter than the current substring
                // then it's the shortest format of the current substring
                if (repeatIndex < len) {
                    string encodedStr = to_string(len / repeatIndex) + '[' + dp[start][repeatIndex] + ']';
                    if (encodedStr.size() < len) {
                        dp[start][len] = encodedStr;
                        continue;
                    }
                }
                // if the current substring can not be written into a shorter encoded format
                // then let's use the recurrence to find the optimal solution
                int optimalCut = 0;
                int shortestLen = len;
                for (int i = 1; i <= len - 1; i++) {
                    int possibleLen = dp[start][i].size() + dp[start + i][len - i].size();
                    if (possibleLen < shortestLen) {
                        shortestLen = possibleLen;
                        optimalCut = i;
                    }
                }
                // contains shorter format
                if (optimalCut > 0) {
                    // string assignment is expensive, so let's do it only once
                    dp[start][len] = dp[start][optimalCut] + dp[start + optimalCut][len - optimalCut];
                } else {
                    dp[start][len] = shortest;
                }
            }
        }

        return dp[0][size];
    }
};
