class Solution {
public:
    map <int, vector <int>> res;
    void DFS(Node* root, int level) {
        if (!root) return;
        else {
            res[level].push_back(root->val);
            for (Node* child: root->children) {
                DFS(child, level + 1);
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        DFS(root, 0);
        vector <vector <int>> ans;
        for (int lev = 0; lev < res.size(); lev++) 
            ans.push_back(res[lev]);
        return ans;
    }
};

