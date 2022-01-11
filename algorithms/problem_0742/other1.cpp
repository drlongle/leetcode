
class Solution {
public:
    void check_nodes_below(TreeNode* root, int &res, int count){
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL){
            if(count<min_val){
                res = root->val;
                min_val = count;
            }
            return;
        }

        check_nodes_below(root->left, res, count+1);
        check_nodes_below(root->right, res, count+1);
    }

    int find_closest_leaf_utils(TreeNode* root, int k, int &res){
        if(root == NULL)
            return INT_MAX;

        if(root->val == k){
            check_nodes_below(root, res, 0);
            return 1;
        }

        int val = find_closest_leaf_utils(root->left, k, res);
        if(val != INT_MAX){
            check_nodes_below(root->right, res, val+1);
            return val+1;
        }

        val = find_closest_leaf_utils(root->right, k, res);
        if(val != INT_MAX){
            check_nodes_below(root->left, res, val+1);
            return val+1;
        }

        return INT_MAX;
    }

    int findClosestLeaf(TreeNode* root, int k) {
        int res=INT_MAX;

        find_closest_leaf_utils(root, k, res);

        return res;
    }
private:
    int min_val = INT_MAX;
};
