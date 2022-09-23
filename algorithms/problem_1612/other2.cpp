class Solution {
  public:
    bool checkEquivalence(Node *root1, Node *root2) {
        vector<int> c1(26, 0), c2(26, 0);
        dfs(c1, root1);
        dfs(c2, root2);

        for (int i = 0; i < 25; i++) {
            if (c1[i] != c2[i])
                return false;
        }
        return true;
    }

    void dfs(vector<int> &m, Node *r) {
        if (!r)
            return;

        if (r->val != '+')
            m[r->val - 'a']++;

        dfs(m, r->left);
        dfs(m, r->right);
    }
};
