struct Trie {
    bool eow = false;
    Trie *children[26];
};

class Solution {
private:
    Trie *root = new Trie();
    int checkWord(string w) {
        int res = 0;
        Trie *curr = root;
        for (int i = w.size() - 1, c; i >= 0; i--) {
            // normalising c
            c = w[i] - 'a';
            // finding a new node
            if (!curr->children[c]) {
                curr->children[c] = new Trie();
                // if it is the last node and a new one, we add its size + 1 to res
                if (!i) res += w.size() + 1;
            }
            // the current word is bigger of a previous one it overlaps
            if (curr->eow) {
                // reducing res accordingly
                res -= w.size() - i;
                // removing eow flag, not to discount the same substring multiple times
                curr->eow = false;
            }
            curr = curr->children[c];
        }
        // checking if the same exact word was already found
        if (curr->eow) return 0;
        curr->eow = res;
        return res;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        return accumulate(begin(words), end(words), 0, [this](int a, string b){return a + checkWord(b);});
    }
};
