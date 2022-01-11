class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int lvl = 1;
        while(!nodeQueue.empty())
        {
            lvl++;
            int size = nodeQueue.size();
            while(size > 0)
            {
                auto tmpNode = nodeQueue.front();
                nodeQueue.pop();

                if(tmpNode->left)
                    nodeQueue.push(tmpNode->left);
                if(lvl == d)
                {
                    TreeNode* newnode = new TreeNode(v);
                    newnode->left = tmpNode->left;
                    tmpNode->left = newnode;
                }

                if(tmpNode->right)
                    nodeQueue.push(tmpNode->right);

                if(lvl == d)
                {
                    TreeNode* newnode = new TreeNode(v);
                    newnode->right = tmpNode->right;
                    tmpNode->right = newnode;
                }
                size--;
            }
        }

        return root;
    }
};
