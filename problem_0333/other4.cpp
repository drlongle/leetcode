
class Solution {
public:
    //Also need to check if its a valid binary search tree if its in the first place
    bool isValidTree(TreeNode*root)
    {
        if(root == nullptr)
            return false;
        //First we have tp
        std::stack<TreeNode*>s;
        TreeNode*prev = nullptr;
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            //Assign to the top
            root  = s.top();
            s.pop();
            if(prev && prev->val >= root->val)
                return false;
            prev = root;
            root = root->right;

        }
        return true;
    }
    int countNode(TreeNode* root)
    {
        if (!root)
            return 0;
        else
            return 1 + countNode(root->left) + countNode(root->right);

    }
    int largestBSTSubtree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(isValidTree(root))
            return countNode(root);
        else
            return std::max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
