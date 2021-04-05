class Solution {
public:
    void util(TreeNode* r, int &ci, vector<int>& v, vector<int> &ans, bool &p){
        if(r){
            if(r->val==v[ci]){
                if(r->left && r->right){
                    if(r->left->val==v[ci+1]){
                        ci++;
                        util(r->left,ci,v,ans,p);
                        ci++;
                        util(r->right,ci,v,ans,p);
                    }
                    else{
                        auto t=r->right;
                        r->right=r->left;
                        r->left=t;
                        ans.push_back(r->val);
                        ci++;
                        util(r->left,ci,v,ans,p);
                        ci++;
                        util(r->right,ci,v,ans,p);
                    }
                }
                else{
                    if(r->left){
                        ci++;
                        util(r->left,ci,v,ans,p);
                    }
                    else if(r->right){
                        ci++;
                        util(r->right,ci,v,ans,p);
                    }
                    else return;
                }
            }
            else{
                p=false;
                return;
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int ci=0;
        bool p=true;
        util(root,ci,voyage,ans,p);
        if(p) return ans;
        else return vector<int>(1,-1);
    }
};
