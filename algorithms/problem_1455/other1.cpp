class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        int word_cnt = 0;
        for (auto i = 0, j = 0; i < sent.size(); ++i) {
            word_cnt += sent[i] == ' ';
            j = sent[i] == word[j] ? j + 1 : 0;
            if (j == word.size())
                return word_cnt;
        }
        return -1;
    }
};
