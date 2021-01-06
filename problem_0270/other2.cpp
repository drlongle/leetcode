class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        double diff = std::numeric_limits<double>::max();
        while (root) {
            double this_diff;
            if (target>=root->val) {
                this_diff = target-(double)root->val;
            } else {
                this_diff = (double)root->val-target;
            }

            if (this_diff < diff) {
                diff = this_diff;
                closest = root->val;
            }
            if (target>root->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return closest;
    }
};
