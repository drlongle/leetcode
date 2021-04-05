class Solution {
public:
    bool dfs(TreeNode *root,vector<int> &answer,const vector<int> &voyage,int &index){
        if(!root)
            return true;
        ++index;
        if(root->val!=voyage[index]) return false;
        if(!dfs(root->left,answer,voyage,index)){
            answer.push_back(root->val);
            --index;
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
            if(!dfs(root->left,answer,voyage,index))
                return false;
        }
        if(!dfs(root->right,answer,voyage,index)){
            answer.push_back(root->val);
            --index;
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
            if(!dfs(root->right,answer,voyage,index))
                return false;
        }
        return true;
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(!root)
            return {};
        vector<int> answer;
        int index=-1;
        if(dfs(root,answer,voyage,index) && index==voyage.size()-1)
            return answer;
        return {-1};
    }
};