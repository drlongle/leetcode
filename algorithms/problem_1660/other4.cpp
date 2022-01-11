class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,TreeNode*>> q{{{root,0}}};

        unordered_set<TreeNode*> st;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;++i)
            {
                auto t = q.front();q.pop();
                TreeNode* cur    = t.first;
                TreeNode* parent = t.second;
                if(st.count(cur->right))
                {
                    if(parent->left  == cur) parent->left  = nullptr;
                    if(parent->right == cur) parent->right = nullptr;
                    return root;
                }
                st.insert(cur);
                if(cur->right) q.push({cur->right,t.first});
                if(cur->left ) q.push({cur->left, t.first});

            }

        }
        return root;
    }
};
