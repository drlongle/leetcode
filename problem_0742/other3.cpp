class Solution {
private:
    // updated:
    // 1. at the node with value k, so that it is the shortest path to a leaf in its subtree
    // 2. at any ancester of k, so that it is  the shortest path to a leaf going through the ancester node
    int result;
    int dis = 1000;

    // returns {dis_to_leaf, leaf_val} if root is not an ancester of k
    // return {dis_to_target, k} if root is k or an ancester of k
    pair<int, int> helper(TreeNode* root, int k) {
        // base case: if root is a leaf, return {0, val}
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == k) {
                result = root->val;
                dis = 0;
            }
            return {0, root->val};
        }

        // var to store left and right sub tree result
        pair<int, int> l = {1000, -1};
        pair<int, int> r = {1000, -1};
        if (root->left != nullptr) {
            l = helper(root->left, k);
        }
        if (root->right != nullptr) {
            r = helper(root->right, k);
        }
        int curr_dis = min(l.first, r.first) +1;
        int curr_res;
        if (curr_dis-1 == l.first) {
            curr_res = l.second;
        } else {
            curr_res = r.second;
        }

        // attempt to update the result if root->val == k
        if (root->val == k) {
            dis = min(dis, curr_dis);
            if (dis == curr_dis) {
                result = curr_res;
            }
            return {0, k};
        }

        // attempt to update the result if root is an ancester of k
        if (l.second == k || r.second == k) {
            int dis_from_k = l.second == k?l.first:r.first;
            int dis_from_leaf = l.second == k?r.first:l.first;
            int leaf = l.second == k?r.second:l.second;
            dis = min(dis, dis_from_leaf + dis_from_k + 2);
            if (dis == dis_from_leaf + dis_from_k+2) {
                result = leaf;
            }
            return {dis_from_k+1, k};
        }

        // pass on value if cannot update result
        return {curr_dis, curr_res};
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        pair<int, int> root_res = helper(root, k);
        if (root_res.second!= k && root_res.first < dis) {
            return root_res.second;
        } else {
            return result;
        }
    }
};
