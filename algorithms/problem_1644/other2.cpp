class ResultType {
public:
    bool p_exist, q_exist;
    TreeNode* lca;
    ResultType(bool p_exist, bool q_exist, TreeNode* node): p_exist(p_exist), q_exist(q_exist), lca(node) {}
};

class SolutionResType {
public:
    ResultType* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return new ResultType(false, false, NULL);
        }
        ResultType* left_res = helper(root->left, p, q);
        ResultType* right_res = helper(root->right, p, q);
        bool p_exist = left_res->p_exist || right_res->p_exist || root == p;
        bool q_exist = left_res->q_exist || right_res->q_exist || root == q;
        if (root == p || root == q) {
            return new ResultType(p_exist, q_exist, root);
        }
        if (left_res->lca != NULL && right_res->lca != NULL) {
            return new ResultType(p_exist, q_exist, root);
        }
        if (left_res->lca != NULL) {
            return new ResultType(p_exist, q_exist, left_res->lca);
        }
        if (right_res->lca != NULL) {
            return new ResultType(p_exist, q_exist, right_res->lca);
        }
        return new ResultType(p_exist, q_exist, NULL);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        ResultType* res = helper(root, p, q);
        if (res->p_exist && res->q_exist) {
            return res->lca;
        }
        return NULL;
    }
};
