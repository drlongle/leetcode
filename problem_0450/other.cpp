class Solution {
public:
    TreeNode* removeNext(TreeNode* root, TreeNode* parent) {
        if (root == nullptr || root->right == nullptr) return nullptr;
        TreeNode* t = root->right, *cur = root;
        while (t != nullptr) {
            parent = cur;
            cur = t;
            t = t->left;
        }
        t = removeNode(cur, parent); 
        return cur;
    }
    
    TreeNode* removeNode(TreeNode* root, TreeNode* parent) {
        if (root == nullptr) return nullptr;
        TreeNode* ret = nullptr;
        if (root->left == nullptr && root->right == nullptr)
            ret = nullptr;
        else if (root->left == nullptr) 
            ret = root->right;
        else if (root->right == nullptr)
            ret = root->left;
        else {
            TreeNode* l=root->left, *r = root->right;
            ret = removeNext(root, parent);
            if (ret) {
                ret->left = l;
                if (ret != r) ret->right = r;
            }
        }
        if (parent != nullptr) {
            if (root->val < parent->val) parent->left = ret;
            else parent->right = ret;
        }
        return ret;
    }
    
    void dfs(TreeNode* root, TreeNode* parent, int key) {
        if (root == nullptr) return;
        if (key < root->val) dfs(root->left, root, key);
        else if (key > root->val) dfs(root->right, root, key);
        else  removeNode(root, parent);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dummy(INT_MAX);
        dummy.left = root;
        dfs(root, &dummy, key);
        return dummy.left;
    }
};
