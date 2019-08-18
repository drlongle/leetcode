vector<int> sums;
void dfs(TreeNode* r, int lvl) {
    if (r != nullptr) {
        if (sums.size() < lvl) sums.resize(lvl);
        sums[lvl - 1] += r->val;
        dfs(r->left, lvl + 1);
        dfs(r->right, lvl + 1);
    }
}
int maxLevelSum(TreeNode* r, int res = 0) {
    dfs(r, 1);
    for (auto i = 1; i < sums.size(); ++i) {
        if (sums[i] > sums[res]) res = i;
    }
    return res + 1;
}
