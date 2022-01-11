class Solution {
public:
    using Set = unordered_set<char>;
    bool halvesAreAlike(string s, Set vowel = Set{ 'a', 'e', 'i', 'o', 'u' }) {
        auto N = s.size();
        auto K = N / 2;
        auto a = s.substr(0, K),
             b = s.substr(K);
        auto isVowel = [&](auto c) { return vowel.find(tolower(c)) != vowel.end(); };
        return count_if(a.begin(), a.end(), isVowel) == count_if(b.begin(), b.end(), isVowel);
    }
};

