
class Solution {
public:
    struct Trie {
        Trie * chars[26] = {};
        char symbol = 0;
        void insert(string &w, char ch, int p = 0) {
            if (p == w.size())
                symbol = ch;
            else {
                if (chars[w[p] - 'a'] == nullptr)
                    chars[w[p] - 'a'] = new Trie();
                chars[w[p] - 'a']->insert(w, ch, p + 1);
            }
        }
        char check(string &w, int p, int sz) {
            if (sz == 0 && symbol != 0)
                return symbol;
            if (w[p] < 'a' || w[p] > 'z' || chars[w[p] - 'a'] == nullptr)
                return 0;
            return chars[w[p] - 'a']->check(w, p + 1, sz - 1);
        }
    };
    vector<pair<string, char>> special = {{"gt", '>'}, {"lt", '<'},
                                          {"amp", '&'}, {"quot", '"'}, {"apos", '\''}, {"frasl", '/'}};
    string entityParser(string &text) {
        Trie root;
        for (auto &[str, ch] : special)
            root.insert(str, ch);
        int st = 0, p = 0;
        for (auto i = 0; i < text.size(); ++i, ++p) {
            text[p] = text[i];
            if (text[p] == '&')
                st = p;
            if (text[p] == ';') {
                auto ch = root.check(text, st + 1, p - st - 1);
                if (ch != 0) {
                    p -= p - st;
                    text[p] = ch;
                }
                st = p + 1;
            }
        }
        text.resize(p);
        return text;
    }
};
