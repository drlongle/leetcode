class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ans(n);
        unordered_map<string, vector<int>> abbrevs;

        // Go through all words in dict
        // Update ans and also record it's abbreviation and index mapping
        for (int i = 0; i < n; i++) {
            string abbrev = abbreviate(dict[i]);
            abbrevs[abbrev].emplace_back(i);
            ans[i] = abbrev;
        }

        // Check duplicate abbreviations
        for (auto& words: abbrevs) {
            // Skip words without duplicates
            if (words.second.size() < 2) continue;

            // Handle the collisions
            auto& indices = words.second;
            int len = indices.size();
            // Use a DP vector to avoid re-calculation of LCP between 2 words
            vector<int> dp(len, 0);
            for (int i = 0; i < len; i++) {
                string& cur_str = dict[indices[i]];
                for (int j = i + 1; j < len; j++) {
                    int sim = LCP(cur_str, dict[indices[j]]);
                    if (sim > dp[i]) dp[i] = sim;
                    if (sim > dp[j]) dp[j] = sim;
                }
                if (dp[i] >= cur_str.length() - 3) {
                    ans[indices[i]] = cur_str;
                } else {
                    string left = cur_str.substr(dp[i]);
                    ans[indices[i]] = cur_str.substr(0, dp[i]) + abbreviate(left);
                }
            }
        }
        return ans;
    }
private:
    // Abbreviate a word
    // For example: "internal" => "i6l"; "cow" => "cow"
    inline string abbreviate(string& str) {
        if (str.length() <= 3) return str;
        return str[0] + to_string(str.length() - 2) + str.back();
    }

    // Check longest common prefix, and return LCP length
    // For example: ("internal", interval") => return 5
    inline int LCP(string& s1, string& s2) {
        if (s1.length() != s2.length()) return 0;
        int i = 0;
        for (; i < s1.length(); i++) {
            if (s1[i] != s2[i]) return i;
        }
        return i;
    }
};
