class Solution {
public:
    using Set = unordered_set<char>;
    using VS = vector<string>;
    int countConsistentStrings(string A, VS& words, int cnt = 0) {
        Set dict{ A.begin(), A.end() };
        for (auto& word: words)
            cnt += all_of(word.begin(), word.end(), [&](auto c) { return dict.find(c) != dict.end(); });
        return cnt;
    }
};
