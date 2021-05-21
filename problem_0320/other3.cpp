class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        // DP: let dp[i] be the abbreviations for word[0:i], we can infer that d[i + 1] will be:
        // 1) all strings from dp[i] + word[i], OR
        // 2) all strings from dp[0:i] where ending character is not number, + "1".
        // So we need to iterate through all previous dp[j] to calculate the dp[i], and the total
        // time complexity is O(n2 * #_of_abbreviations);
        int size = word.size();
        vector<vector<string>> dp(size);
        dp[0] = {"1", word.substr(0, 1)};

        for (int i = 1; i < size; ++i)
        {
            vector<string> abbs;
            for (string& s : dp[i - 1])
            {
                abbs.push_back(s + word.substr(i, 1));
            }

            for (int j = 0; j < i; ++j)
            {
                for (string& s : dp[j])
                {
                    char c = s.back();
                    if (c <= 'z' && c >= 'a')
                    {
                        abbs.push_back(s + to_string(i - j));
                    }
                }
            }

            abbs.push_back(to_string(i + 1));
            dp[i] = abbs;
        }

        return dp[size - 1];
    }
};
