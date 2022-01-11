class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    vector<int> vals;
};

class WordFilter {
private:
    TrieNode *pTrie, *sTrie;

public:
    WordFilter(vector<string>& words) {
        pTrie = new TrieNode();
        sTrie = new TrieNode();
        for (int index = 0; index < words.size(); index++) {
            string word = words[index];
            insert(word, index, pTrie);
            reverse(word.begin(), word.end());
            insert(word, index, sTrie);
        }
    }

    void insert(string word, int index, TrieNode* trie) {
        for (auto c : word) {
            int cval = c - 'a';
            if (!trie->children[cval])
                trie->children[cval] = new TrieNode();
            trie = trie->children[cval];
            trie->vals.push_back(index);
        }
    }

    vector<int>* retrieve(string str, TrieNode* trie) {
        for (auto c : str) {
            trie = trie->children[c-'a'];
            if (!trie) return nullptr;
        }
        return &trie->vals;
    }

    int f(string pre, string suf) {
        vector<int>* pVals = retrieve(pre, pTrie);
        reverse(suf.begin(), suf.end());
        vector<int>* sVals = retrieve(suf, sTrie);
        int svix = sVals->size() - 1, pvix = pVals->size() - 1;
        while (svix>= 0 && pvix>= 0) {
            int sVal = (*sVals)[svix], pVal = (*pVals)[pvix];
            if (sVal == pVal) return sVal;
            if (sVal > pVal) svix--;
            else pvix--;
        }
        return -1;
    }
};
