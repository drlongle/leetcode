/*
Regardless whether these nodes exist:

Always make the id of left child as parent_id * 2;
Always make the id of right child as parent_id * 2 + 1;
So we can just:
- Record the id of left most node when first time at each level of the tree during an pre-order run.
  (you can tell by check the size of the container to hold the first nodes);
- At each node, compare the distance from it the left most node with the current max width;
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        return dfs(root, 1, 0, lefts);
    }
private:
    int dfs(TreeNode* n, int id, int d, vector<int>& lefts) { // d : depth
        if (!n) return 0;
        if (d >= lefts.size()) lefts.push_back(id);  // add left most node
        return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts), dfs(n->right, id * 2 + 1, d + 1, lefts)});
    }
};
