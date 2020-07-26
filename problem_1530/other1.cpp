/*
find all the leaf depth from left child and the right child and
calculate the distance left_leaf_depth - root_depth + right_leaf_depth- root_depth - right
*/

class Solution {
public:
    int ans = 0;
    map<int, int> dfs(TreeNode* root, int d, int dist) {
        if(!root) return {};
        map<int, int> m;
        if(!root->left && !root->right) {
            ++m[d]; return m;
        }
        
        auto l = dfs(root->left, d + 1, dist);
        auto r = dfs(root->right, d + 1, dist);
        for(auto &lit : l) {
            int dl = lit.first - d;
            for(auto &rit : r){
                int dr = rit.first - d;
                if((dl + dr) <= dist) {
                    ans += lit.second * rit.second;
                }
            }
        }
        for(auto &rit : r) {
            l[rit.first] += rit.second;
        }
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, 0, distance);
        return ans;
    }
};
