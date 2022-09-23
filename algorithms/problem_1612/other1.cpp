class Solution {
  public:
    void fun(Node *root1, vector<int> &s) {
        if (!root1)
            return;
        if (root1->val != '+')
            s[root1->val - 'a']++;
        fun(root1->left, s);
        fun(root1->right, s);
    }
    bool checkEquivalence(Node *root1, Node *root2) {
        vector<int> s1(26, 0);
        vector<int> s2(26, 0);
        fun(root1, s1);
        fun(root2, s2);
        return (s1 == s2);
    }
};
