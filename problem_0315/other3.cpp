
// BST
class Treenode{
public:
    Treenode *left;
    Treenode *right;
    int val;
    int less_than;

    Treenode(int val, int less_than){
        left = right = NULL;
        this->val = val;
        this->less_than = less_than;
    }
};

class Solution {

    Treenode* insert(Treenode* root, int value, int index, int sum, vector<int>& res){

        if(root == NULL){
            res[index] = sum;
            return new Treenode(value, 0);
        }

        if(value < root->val) {
            root->less_than++;
            root->left = insert(root->left, value, index, sum, res);
        }else if(value > root->val)
            root->right = insert(root->right, value, index, sum+root->less_than+1, res);
        else
            root->right = insert(root->right, value, index, sum+root->less_than, res);

        return root;
    }

public:

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        if(n == 0)
            return {};

        Treenode* root = NULL;
        vector<int> counts(n);

        for(int i=n-1; i>=0; i--)
            root = insert(root, nums[i], i, 0, counts);

        return counts;
    }
};
