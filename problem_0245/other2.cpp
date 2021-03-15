class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int min_{1212121}, i1{-1212121}, i2{-1212121};
        for(size_t i{0}, size{words.size()}; i < size; ++i) {
            if(words[i] == word1) i1 = i, min_ = min(min_, i1-i2);
            if(words[i] == word2) i2 = i, min_ = min(min_, i2-i1);
        }
        return min_;
    }
    static constexpr inline int min(int a, int b) {return b == 0 ? a : std::min(a,b);};
};
