struct TrieNode {
    bool isWord;
    vector<TrieNode*> children;
    TrieNode(): isWord(false), children(128, nullptr) {}
};

class Solution {
    void insert(TrieNode* root, const string& product) {
        TrieNode* cur = root;
        for (char c: product) {
            if (!cur->children[c])
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    void dfs(TrieNode* node, string& prefix, vector<string>& curList) {
        if (!node) return;
        if (node->isWord) curList.push_back(prefix);
        for (int i = 'a'; i <= 'z'; ++i) {
            if (node->children[i] && curList.size() < 3) {
                prefix.push_back(i);
                dfs(node->children[i], prefix, curList);
                prefix.pop_back();
            }
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (const auto& p: products)
            insert(root, p);
        
        vector<vector<string>> res;
        string prefix;
        for (char c: searchWord) {
            prefix.push_back(c);
            vector<string> curList;
            if (!root) {
                res.push_back(curList);
                continue;
            }
            root = root->children[c];
            TrieNode* cur = root;
            dfs(cur, prefix, curList);
            res.push_back(curList);
        }
        return res;
    }
};
