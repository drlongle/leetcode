class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        unordered_map<int, unordered_map<int, vector<TreeNode *>>> mp;
        return solve(1, n, mp);
    }
    
    vector<TreeNode *> solve(int n1, int n2, unordered_map<int,  unordered_map<int, vector<TreeNode *>>> &mp) {
        if (n1 > n2) return {nullptr};
        if (n1 == n2) return {new TreeNode(n1)};
        vector<TreeNode *> ans;
        if (mp.find(n1) != mp.end() and mp[n1].find(n2) != mp[n1].end()) return mp[n1][n2];
        for(int i=n1; i<=n2; i++) {
            vector<TreeNode *> left = solve(n1, i - 1, mp);
            vector<TreeNode *> right = solve(i + 1, n2, mp);
            for (auto l: left) {
                for (auto r: right){
                    TreeNode *nd = new TreeNode(i);
                    nd->left = l;
                    nd->right = r;
                    ans.push_back(nd);
                }
            }
        }
        mp[n1][n2] = ans;
        return ans;
    }
};

