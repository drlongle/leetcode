/*
Idea: We have met two nodes find its lca problem, we can use it here to solve this problem

Step:
Calculate the height
Do a pre-order traverse to find all the deepest leaves, and add them into a queue.
Do the divide and conquer stategy here. Everytime, we use the first two node in the queue and find their lca, push back to the tail of the queue, untill the queue is only having one node left, and that should be the node we've been looking.
*/

    int depth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    TreeNode* commonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {
        if (!root || root == A || root == B)
            return root;
        TreeNode *left = commonAncestor(root->left, A, B);
        TreeNode *right = commonAncestor(root->right, A, B);
        if (!left)
            return right;
        else if (!right)
            return left;
        else
            return root;
    }
    void helper(TreeNode* root, int cur, int& height, queue<TreeNode*>& cand) {
        if (!root)
            return;
        if (height == cur + 1) {
            if (root->left)
                cand.push(root->left);
            if (root->right)
                cand.push(root->right);
            return;
        }
        helper(root->left, cur + 1, height, cand);
        helper(root->right, cur + 1, height, cand);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> cand;
        int height = depth(root);
        helper(root, 1, height, cand);
        while (cand.size() > 1) {
            TreeNode *A = cand.front();
            cand.pop();
            TreeNode *B = cand.front();
            cand.pop();
            TreeNode *lca = commonAncestor(root, A, B);
            cand.push(lca);
        }
        return cand.front();
    }

