class Solution {
public:
    static bool wordBreak(const string& s, const vector<string>& wordDict) {
        if (s.empty()) return true;
        vector<bool> cache(s.length());
        return wordBreakRec(s, wordDict, 0, cache);
    }

    static bool wordBreakRec(const string& s, const vector<string>& wordDict, int startIndex, vector<bool>& cache) {
        if (startIndex >= s.length()) return true;
        if (cache[startIndex]) return false;
        for (const string& word : wordDict) {
            if (startsWith(s, startIndex, word)) {
                if (wordBreakRec(s, wordDict, startIndex + word.length(), cache)) return true;
            }
        }
        cache[startIndex] = true;
        return false;
    }

    static bool startsWith(const string& s, int startIndex, const string& word) {
        if (startIndex + s.length() < word.length()) return false;
        for (int i = 0; i < word.length(); ++i) if (s[i + startIndex] != word[i]) return false;
        return true;
    }
};
