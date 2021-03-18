class Solution {
public:
    bool dfs(vector<int>& a,int &i, int min, int max) {
        if (i >= a.size()) return true;
        int root_val = a[i];
        if (root_val < min || root_val > max) return false;
        i++;
        bool left = dfs(a, i, min, root_val);
        bool right = dfs(a, i, root_val, max);
        return left || right;
    }
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(preorder, i, INT_MIN, INT_MAX);
    }
};
