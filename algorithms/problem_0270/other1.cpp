class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res;
        double difference;
        double tempDiff;
        res = root->val;
        difference = abs(target-root->val);

        TreeNode* curr = root;
        while( curr ){
            tempDiff = abs( curr -> val - target);
            if( tempDiff < difference){
                difference = tempDiff;
                res = curr -> val;
            }
            if( target == curr ->val){
                return curr -> val;
            }
            else if( target < curr ->val){
                curr = curr -> left;
            }else{
                curr = curr -> right;
            }
        }

        return res;
    }
};
