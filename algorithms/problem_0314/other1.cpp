class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map <int, vector <int>> hash;
        queue <pair<TreeNode*, int>> que;
        que.push({root, 0});
        while(!que.empty()){
            pair <TreeNode*, int> curr = que.front();
            que.pop();
            hash[curr.second].push_back(curr.first->val);
            if(curr.first -> left)
                que.push({curr.first->left, curr.second - 1});
            if(curr.first -> right)
                que.push({curr.first->right, curr.second + 1});
        }
        vector <vector <int>> res;
        for(auto [_, value]: hash)
            res.push_back(value);
        return res;
    }
};
