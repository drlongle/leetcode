class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> nodes;
        traverse(root, 0, 0, nodes);
        for (auto node : nodes)
        {
            vector<int> cols;
            for (auto col : node.second)
            {
                cols.insert(cols.end(), col.second.begin(), col.second.end());
            }
            ans.push_back(cols);
        }

        return ans;

    }
private:
    void traverse(TreeNode* root, int x, int y, map<int, map<int, vector<int>>>& nodes) {
        if (root) {
            nodes[x][y].push_back(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};
