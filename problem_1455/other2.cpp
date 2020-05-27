class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {                        
        auto it = (' ' + sentence).find(' ' + searchWord);        
        return it ==string::npos ? -1: count(begin(sentence), begin(sentence) + it, ' ') + 1; 
    }
};
